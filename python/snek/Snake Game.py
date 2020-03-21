import pygame
import time
import random
	

pygame.init() #initializes module
	

white=(255,255,255) #colours
black=(0,0,0)
red=(255,0,0)
green=(0,255,0)
blue=(0,0,255)
colours=[white,black,red,green,blue]
	

display_width=1000 #size of screen
display_height=800
	

gameDisplay=pygame.display.set_mode((display_width,display_height))
pygame.display.set_caption('Snek')#name
	
snekImg=pygame.image.load('snek.png')#snek image
appleImg=pygame.image.load('apple.png')#apple image
	
clock=pygame.time.Clock()#fps
	

block_size=20
FPS=10

direction ="right"	

status_font=pygame.font.SysFont(None, 25) #font
	

def snake(block_size, snakelist):
    if direction=="right":
        head=pygame.transform.rotate(snekImg,270) #rotates head
    if direction=="left":
        head=pygame.transform.rotate(snekImg,90)
    if direction=="up":
        head=snekImg
    if direction=="down":
        head=pygame.transform.rotate(snekImg,180)
    
    gameDisplay.blit(head,(snakelist[-1][0],snakelist[-1][1])) #snek head
    for XnY in snakelist[:-1]:
        pygame.draw.rect(gameDisplay, green, [XnY[0],XnY[1],block_size,block_size])#colour,x start, y start, width, height 
	    
	
def text_objects(text,color):
    textSurface=status_font.render(text,True,color)
    return textSurface,textSurface.get_rect()


def message_to_screen(msg,color,y_displace=0): #game over message
    textSurf,textRect=text_objects(msg,color)
    textRect.center=(display_width/2),(display_height/2)+y_displace
    gameDisplay.blit(textSurf,textRect)

def score(score): #score
    text=status_font.render("Score:"+str(score),True,black)
    gameDisplay.blit(text,[0,0])

def pause():
    paused=True
    while paused:
        for event in pygame.event.get():
            if event.type==pygame.QUIT:
                pygame.quit()
                quit()
            if event.type==pygame.KEYDOWN:
                if event.key==pygame.K_SPACE:
                    paused=False
                elif event.key==pygame.K_ESCAPE:
                    pygame.quit()
                    quit()
        gameDisplay.fill(white)
        message_to_screen("Paused",blue,-100)
        message_to_screen("Press Space to continue or Escape to quit.",blue,25)
        pygame.display.update()
        clock.tick(4)
        

def game_intro(): #game intro
    intro=True
    while intro:
        for event in pygame.event.get():
            if event.type==pygame.QUIT:
                pygame.quit()
                quit()
            if event.type==pygame.KEYDOWN:
                if event.key==pygame.K_SPACE:
                    intro=False
                if event.key==pygame.K_ESCAPE:
                    pygame.quit()
                    quit()

        
        gameDisplay.fill(white)
        message_to_screen("Welcome to Snek!", black,-200)
        message_to_screen("Press Space to play, or Escape to quit",black)
        pygame.display.update()
        clock.tick(5)
                       
	

	

def gameLoop():#runs program
    running=True
    lose=False

    global direction	

    lead_x=display_width/2 #spawn point
    lead_y=display_height/2
	

    lead_x_change=0
    lead_y_change=0
	

    snakeList=[]
    snakeLength=1
	

    randAppleX=round(random.randrange(0, display_width-block_size))##spawns apple randomly
    randAppleY=round(random.randrange(0, display_height-block_size))
	    
    while running:
	

        while lose==True:
            gameDisplay.fill(white)
            message_to_screen("Game over, press Space to play again or Escape to quit", red)
            pygame.display.update()
	

            for event in pygame.event.get():
                if event.type==pygame.QUIT:
                    lose=False
                    running=False
	                    
                if event.type==pygame.KEYDOWN:
                    if event.key==pygame.K_ESCAPE:
                        running=False
                        lose=False
                    if event.key == pygame.K_SPACE:
                        gameLoop()
	

	        
        for event in pygame.event.get():
            if event.type==pygame.QUIT:
                running=False
            if event.type==pygame.KEYDOWN:
                if event.key==pygame.K_LEFT: #moves left
                    lead_x_change=-block_size
                    direction="left" 
                    lead_y_change=0
                elif event.key==pygame.K_RIGHT: #moves right
                    lead_x_change=block_size
                    direction="right"
                    lead_y_change=0
                elif event.key==pygame.K_UP: #moves up
                    lead_y_change=-block_size
                    direction="up"
                    lead_x_change=0
                elif event.key==pygame.K_DOWN: #moves down
                    lead_y_change=block_size
                    direction="down"
                    lead_x_change=0
                elif event.key==pygame.K_ESCAPE:
                    pause()
	

        if lead_x>=display_width or lead_x < 0 or lead_y >= display_height or lead_y < 0: #border for snek
            lose=True
	      
	

        
        lead_x+=lead_x_change#moves snek
        lead_y+=lead_y_change
	        
        gameDisplay.fill(white)#background
	

        AppleThickness=30 #apple
        gameDisplay.blit(appleImg,(randAppleX, randAppleY))
	        
        snakeHead=[]
        snakeHead.append(lead_x)
        snakeHead.append(lead_y)
        snakeList.append(snakeHead)
	

        if len(snakeList) > snakeLength:
            del snakeList[0]
	

        for eachSegment in snakeList[:-1]: #if snake bites itself, it dies
            if eachSegment==snakeHead:
                lose=True


	        
        snake(block_size, snakeList)
	
        score(snakeLength-1)
        
        pygame.display.update()#shows snek bigger
	



        if lead_x>randAppleX and lead_x<randAppleX+AppleThickness or lead_x+block_size>randAppleX and lead_x+block_size<randAppleX+AppleThickness:
            if lead_y>randAppleY and lead_y<randAppleY+AppleThickness:
                randAppleX=round(random.randrange(0, display_width-block_size))
                randAppleY=round(random.randrange(0, display_height-block_size))
                snakeLength+=1

            elif lead_y+block_size>randAppleY and lead_y+block_size<randAppleY+AppleThickness:
                randAppleX=round(random.randrange(0, display_width-block_size))
                randAppleY=round(random.randrange(0, display_height-block_size))
                snakeLength+=1       
	

        clock.tick(FPS)#makes the snake not move 1000000 miles per hour
        
    gameDisplay.fill(black)
    message_to_screen("You Lose", red)
    pygame.display.update()

    time.sleep(2)
    pygame.quit()#quits
    quit()
	

	
game_intro()
gameLoop()#starts function
