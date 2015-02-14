bg = 'yellow.jpg'
icon = 'smile.png'

import pygame
from pygame.locals import *
from sys import exit

pygame.init()

screen = pygame.display.set_mode((500, 500), 0, 32)
pygame.display.set_caption('Hello People')

bg_img = pygame.image.load(bg).convert()
icon_img = pygame.image.load(icon).convert_alpha()

while True:
	for event in pygame.event.get():
		if event.type == QUIT:
			del bg
			del icon
			pygame.display.quit()
			exit(0)

	screen.blit(bg_img, (0,0))

	x, y = pygame.mouse.get_pos()

	x -= icon_img.get_width() / 2
	y -= icon_img.get_width() / 2
	i = 20
	while i < 220:
		screen.blit(bg_img, (0,0))
		screen.blit(icon_img, (i, i))
		i += 1

		pygame.display.update()
	pygame.display.update()