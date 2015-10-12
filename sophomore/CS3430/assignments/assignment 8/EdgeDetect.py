import Image
import ImageFilter


def filterFindEdges(im):
    
    im1 = im.filter(ImageFilter.FIND_EDGES)
    
    im1.save("EDGES.jpg")


imageFile = "LEAF.jpg"
im1 = Image.open(imageFile)
filterFindEdges(im1)
    
