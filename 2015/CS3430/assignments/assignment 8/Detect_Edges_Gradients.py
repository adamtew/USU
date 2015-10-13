import math
import Image

def luminosity(rgb, rcoeff=0.2126, gcoeff=0.7152, bcoeff=0.0722):
    return rcoeff*rgb[0]+gcoeff*rgb[1]+bcoeff*rgb[2]

## im is a PIL Image object.
def is_in_range(im, c, r):
    return c > 0 and c < im.size[0]-1 and r > 0 and r < im.size[1]-1

## In PIL, c = x, r = y
def rgb_pix_dy(rgb_img, c, r, lumin=luminosity, default_delta=1.0):
    if not is_in_range(rgb_img, c, r): return default_delta
    dy = lumin(rgb_img.getpixel((c, r-1))) - lumin(rgb_img.getpixel((c,r+1)))
    if dy == 0:
        return default_delta
    else:
        return float(dy)

def rgb_pix_dx(rgb_img, c, r, lumin=luminosity, default_delta=1.0):
    if not is_in_range(rgb_img, c, r): return default_delta
    dx = lumin(rgb_img.getpixel((c+1, r))) - lumin(rgb_img.getpixel((c-1, r)))
    if dx == 0:
        return default_delta
    else:
        return float(dx)

def gradient_magnitude(pdx, pdy):
    return math.sqrt(math.pow(pdx, 2.0) + math.pow(pdy, 2.0))

## if pdy == pdx, we return a default_theta value outside of [-pi, pi]
## gradient orientation
def gradient_theta(rgb_img, c, r, lumin=luminosity, default_delta=1.0, default_theta=-200):
    if not is_in_range(rgb_img, c, r): return default_theta
    pdy, pdx = rgb_pix_dy(rgb_img, c, r, lumin=lumin), rgb_pix_dx(rgb_img, c, r, lumin=lumin)
    if pdy == pdx == default_delta: return default_theta
    th = math.atan2(pdy,pdx)*(180/math.pi)
    if th < 0:
        return math.floor(th)
    elif th > 0:
        return math.ceil(th)
    else:
        return th

def gen_pix_factory(im):
    num_cols, num_rows = im.size
    r, c = 0, 0
    while r != num_rows:
        c = c % num_cols
        yield ((c, r), im.getpixel((c, r)))
        if c == num_cols - 1: r += 1
        c += 1

def detect_rgb_edges(input_rgb_img,
                     grad_theta=gradient_theta,
                     grad_magn=gradient_magnitude,
                     pixdx=rgb_pix_dx,
                     pixdy=rgb_pix_dy,
                     lumin=luminosity,
                     default_delta=1.0,
                     default_theta=-200,
                     theta_thresh=360,
                     magn_thresh=20):
    output_img = Image.new('L', input_rgb_img.size)
    gen_pix = gen_pix_factory(input_rgb_img)
    theta_grad_pix = ((gpix[0],
                       int(grad_theta(input_rgb_img, gpix[0][0], gpix[0][1],
                                      lumin=lumin,
                                      default_delta=default_delta,
                                      default_theta=default_theta)),
                       int(grad_magn(pixdx(input_rgb_img, gpix[0][0], gpix[0][1],
                                           lumin=lumin, default_delta=default_delta),
                                     pixdy(input_rgb_img, gpix[0][0], gpix[0][1],
                                           lumin=lumin, default_delta=default_delta))))
                      for gpix in gen_pix)
    for tg_pix in theta_grad_pix:
        coords, theta, gmagn = tg_pix        
        if  abs(theta) <= theta_thresh and gmagn >= magn_thresh:
            output_img.putpixel(coords, 255)
        else:
            output_img.putpixel(coords, 0)
    return output_img

'''usage
input_image = Image.open('Image path')
output_image=detect_rgb_edges(input_image)
output_image.save('image name.JPG')
'''
