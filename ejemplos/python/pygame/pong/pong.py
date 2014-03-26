#!/usr/bin/python
# -*- coding: utf-8 -*-
#
# Juego Pong
#
# Autor original: Adrián Guerra Marrero
# Modificaciones: Esteban De La Fuente Rubio
#
# Pygame utiliza Python 2, en Debian GNU/Linux instalar:
#  # apt-get install python-pygame
#
# Referencias:
#  - http://razonartificial.com/tutoriales-pygame
#

# Módulos
import sys
import os
import pygame
from pygame.locals import *
import random

# Configuración
BOLA_VELOCIDAD = 0.4
PALA_VELOCIDAD = 0.3
JUGADOR_DISTANCIA_PARED = 20
JUGADOR1 = (True, (K_UP, K_DOWN))
JUGADOR2 = (True, (K_q, K_a))

# Constantes
TITLE  = "Pong"
WIDTH  = 640
HEIGHT = 480

# clase para la bola
class Bola (pygame.sprite.Sprite) :
	# constructor de la bola
	def __init__ (self) :
		pygame.sprite.Sprite.__init__(self)
		self.image = load_image(os.path.join("images", "bola.png"), True)
		self.rect = self.image.get_rect()
		self.velocidad = BOLA_VELOCIDAD
		self.velocidades = [[self.velocidad, self.velocidad], [-self.velocidad, self.velocidad], [self.velocidad, -self.velocidad], [-self.velocidad, -self.velocidad]]
		self.lanzar()
	# método que inicia la bola desde el centro de la pantalla en dirección random
	def lanzar (self) :
		# posición inicial
		self.rect.centerx = WIDTH / 2
		self.rect.centery = HEIGHT / 2
		# velocidad inicial
		self.speed = self.velocidades[random.randrange(0, 3)]
	# método para mover la bola por la pantalla
	def mover (self, time, jugador1, jugador2) :
		# mover la bola en la dirección actual
		self.rect.centerx += self.speed[0] * time
		self.rect.centery += self.speed[1] * time
		# actualizar puntaje para los jugadores en caso de que se haya pasado la barra
		if self.rect.left <= 0:
			jugador2.puntaje += 1
			self.lanzar()
		if self.rect.right >= WIDTH:
			jugador1.puntaje += 1
			self.lanzar()
		# si se topó el borde de la izquierda o derecha se cambia la dirección horizontal de la bola
		if self.rect.left <= 0 or self.rect.right >= WIDTH:
			self.speed[0] = -self.speed[0]
			self.rect.centerx += self.speed[0] * time
		# si se topó el borde de arriba o abajo se cambia la dirección vertical de la bola
		if self.rect.top <= 0 or self.rect.bottom >= HEIGHT:
			self.speed[1] = -self.speed[1]
			self.rect.centery += self.speed[1] * time
		# si se colisiona con la pala del jugador se rebota
		if pygame.sprite.collide_rect(self, jugador1.pala) :
			self.speed[0] = -self.speed[0]
			self.rect.centerx += self.speed[0] * time
		# si se colisiona con la pala del oponente se rebota
		if pygame.sprite.collide_rect(self, jugador2.pala) :
			self.speed[0] = -self.speed[0]
			self.rect.centerx += self.speed[0] * time

# clase para el jugador
class Jugador :
	# constructor del jugador
	def __init__ (self, id, ia = False, keys = (K_UP, K_DOWN)) :
		self.id = id
		if self.id == 1 :
			self.pala = Pala(JUGADOR_DISTANCIA_PARED)
		else :
			self.pala = Pala(WIDTH-JUGADOR_DISTANCIA_PARED)
		self.keys = keys
		self.ia = ia
		self.puntaje = 0
	# método para mover la pala del jugador
	def mover (self, time, keys, bola) :
		self.pala.mover(time, keys, bola, self)
		
# clase para la pala del jugador
class Pala (pygame.sprite.Sprite) :
	# constructor de la pala
	def __init__ (self, x):
		pygame.sprite.Sprite.__init__(self)
		self.image = load_image(os.path.join("images", "pala.png"))
		self.rect = self.image.get_rect()
		self.rect.centerx = x
		self.rect.centery = HEIGHT / 2
		self.speed = PALA_VELOCIDAD
	# método para mover la pala por la pantalla
	def mover (self, time, keys, bola, jugador) :
		# si es un jugador real mover según teclas
		if not jugador.ia :
			# mover la pala hacia arriba (sin que se salga de los límites)
			if self.rect.top >= 0 :
				if keys[jugador.keys[0]] :
					self.rect.centery -= self.speed * time
			# mover la pala hacia abajo (sin que se salga de los límites)
			if self.rect.bottom <= HEIGHT :
				if keys[jugador.keys[1]] :
					self.rect.centery += self.speed * time
		# si no es real se debe aplicar IA (inteligencia artificial)
		else :
			# si la pelota va hacia el jugador y esta en su lado
			if (jugador.id == 1 and bola.speed[0] <= 0 and bola.rect.centerx <= WIDTH/2) or (jugador.id == 2 and bola.speed[0] >= 0 and bola.rect.centerx >= WIDTH/2):
				if self.rect.centery < bola.rect.centery:
					self.rect.centery += self.speed * time
				if self.rect.centery > bola.rect.centery:
					self.rect.centery -= self.speed * time

# función para cargar una imagen
def load_image (filename, transparent=False) :
	try: image = pygame.image.load(filename)
	except pygame.error, message:
		raise SystemExit, message
	image = image.convert()
	if transparent:
		color = image.get_at((0,0))
		image.set_colorkey(color, RLEACCEL)
	return image

# función para dibuhar un texto en la pantalla
def texto (texto, posx, posy, color=(255, 255, 255)) :
	fuente = pygame.font.Font("fonts/DroidSans.ttf", 25)
	salida = pygame.font.Font.render(fuente, texto, 1, color)
	salida_rect = salida.get_rect()
	salida_rect.centerx = posx
	salida_rect.centery = posy
	return salida, salida_rect

# Programa principal
def main():
	# inicializar pygame (se inicializará todo por simplicidad)
	pygame.init()
	# crear ventana
	screen = pygame.display.set_mode((WIDTH, HEIGHT))
	pygame.display.set_caption(TITLE)
	# reloj para gestionar el tiempo que ha pasado en el juego
	clock = pygame.time.Clock()
	# crear fondo
	background_image = load_image(os.path.join("images", "fondo_pong.png"))
	# crear bola
	bola = Bola()
	# crear jugadores
	jugador1 = Jugador(1, JUGADOR1[0], JUGADOR1[1])
	jugador2 = Jugador(2, JUGADOR2[0], JUGADOR2[1])
	# bucle infinito para el juego
	salir = False
	while not salir:
		# tiempo que ha pasado entre cada iteración, el parámetro (ej: 60) es el framerate
		time = clock.tick(60)
		# teclas que se han presionado
		keys = pygame.key.get_pressed()
		# revisar teclas presionadas
		if keys[K_ESCAPE] :
			salir = True
		# revisar eventos que se puedan estar ejecutando
		for evento in pygame.event.get() :
			# procesar eventos
			if evento.type == QUIT :
				salir = True
		# actualizar objetos
		bola.mover(time, jugador1, jugador2)
		jugador1.mover(time, keys, bola)
		jugador2.mover(time, keys, bola)
		# puntaje para los jugadores
		p_jugador1, p_jugador1_rect = texto(str(jugador1.puntaje), WIDTH/4, 40)
		p_jugador2, p_jugador2_rect = texto(str(jugador2.puntaje), WIDTH-WIDTH/4, 40)
		# dibujar objetos en la pantalla
		screen.blit(background_image, (0, 0))
		screen.blit(bola.image, bola.rect)
		screen.blit(jugador1.pala.image, jugador1.pala.rect)
		screen.blit(jugador2.pala.image, jugador2.pala.rect)
		screen.blit(p_jugador1, p_jugador1_rect)
		screen.blit(p_jugador2, p_jugador2_rect)
		# actualizar pantalla
		pygame.display.flip()
	# retornar al sistema
	sys.exit(0)

# si el programa se cargo de forma directa (no como módulo) se ejecuta la función main()
if __name__ == '__main__':
	main()
