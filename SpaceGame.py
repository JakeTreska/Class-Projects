import pygame
from pygame import mixer
import math
import random
# initialize
pygame.init()
# Setting up the background
screen = pygame.display.set_mode((0, 0), pygame.FULLSCREEN)
pygame.display.set_caption(("SPACE FROGGER"))
background = pygame.image.load("space.png.jpg")
background2 = pygame.image.load("Space2.png.jpg")
# Setting up the player
x = 0
player = pygame.image.load('spaceship copy.png')
player2 = pygame.image.load('spaceship2.png')
playerx = 400
playery = 800
player_x_change = 0
player_y_change = 0
# Setting up background music
mixer.music.load('Background.wav')
mixer.music.play(-1)
explosion = mixer.Sound('explosion.wav')
# score
score_value = 0
font = pygame.font.Font('freesansbold.ttf',32)
textx = 10
texty = 30
# Lives
lives = 3
# Displaying score
def ShowScore(x,y):
     #Receiving High Score
    score = font.render("Score : " + str(score_value), True, (255,255,255))
    screen.blit(score,(x,y))
    live_score = font.render("Lives : " + str(lives), True, (255, 255, 255))
    screen.blit(live_score, (x+1200, y))
# Setting up the enemies
number_of_enemies = 15
enemy = []
enemyx = []
enemyy = []
enemy_x_change = []
for i in range(number_of_enemies):
    speed = random.randint(100,200) / 90
    y = random.randint(40,750)
    enemy.append(pygame.image.load('comet.png'))
    enemyx.append(0)
    enemyy.append(y)
    enemy_x_change.append(speed)

def IsCollision(x2,y2,x1,y1):
    d = math.sqrt(math.pow(x2-x1,2)+(math.pow(y2-y1,2)))
    if d <= 20:
        return True

#main game loop
running = True
while running:
    if score_value >= 5:
        screen.blit(background2, (0, 0))
    else:
        screen.blit(background, (0, 0))
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False
        # Game controls
        if event.type == pygame.KEYDOWN:
            if event.key == pygame.K_LEFT:
                player_x_change = -1
            if event.key == pygame.K_RIGHT:
                player_x_change = 1
            if event.key == pygame.K_DOWN:
                player_y_change = 1
            if event.key == pygame.K_UP:
                player_y_change = -1
        if score_value < 5:
            if event.type == pygame.KEYUP:
                if event.key == pygame.K_LEFT or event.key == pygame.K_RIGHT:
                    player_x_change = 0
                if event.key == pygame.K_UP or event.key == pygame.K_DOWN:
                    player_y_change = 0
        elif score_value >= 5:
            if event.type == pygame.KEYUP:
                if event.key == pygame.K_LEFT:
                    player_x_change = -0.3
                if event.key == pygame.K_RIGHT:
                    player_x_change = 0.3
                if event.key == pygame.K_UP:
                    player_y_change = -0.3
                if event.key == pygame.K_DOWN:
                    player_y_change = 0.3

    # player border checking
    playerx += player_x_change
    playery += player_y_change
    if playerx >=1400:
        playerx = 1400
    if playerx <= 15:
        playerx = 15
    if playery >= 850:
        playery = 850
    if playery <= 30:
        score_value += 1
        playery = 800
    if score_value >= 5:
        screen.blit(player2, (playerx, playery))
    else:
        screen.blit(player, (playerx, playery))
    for i in range(number_of_enemies):
        enemyx[i] += enemy_x_change[i]
        screen.blit(enemy[i], (enemyx[i], enemyy[i]))
        if enemyx[i] >= 1500:
            enemyx[i] = 0

        if IsCollision(playerx, playery, enemyx[i], enemyy[i]):
            explosion.play()
            lives -= 1
            playery = 815
            playerx = 500
            player_y_change, player_x_change = 0,0
            screen.blit(player, (playerx, playery))
            if lives == 0:
                running = False
    ShowScore(textx,texty)
    pygame.display.update()

