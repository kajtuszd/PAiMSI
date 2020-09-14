import pygame

(f_width, f_height) = (600,600)

class Game(pygame.sprite.Sprite):

    def __init__(self):
        pygame.sprite.Sprite.__init__(self)

    def draw_frame(self, screen):
        pygame.draw.rect(screen, (0,250,0), (0, 30, 600, 600), 5)

    def draw_white_rect(self, screen):
        pygame.draw.rect(screen, (255, 255, 255), (0, 0, 600, 30))

    def wait(self):
        flag = True
        while flag:
            for event in pygame.event.get():
                if event.type == pygame.KEYDOWN:
                    if event.key == pygame.K_ESCAPE:
                        return True
                    if event.key == pygame.K_p:
                        flag = False
                        return False

