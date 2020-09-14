import pygame

GREEN = (0, 255, 0)
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

    def render_welcome_view(self, screen):
        font = pygame.font.SysFont('dejavuserif', 30, True, True)
        flag = True
        while flag:
            for event in pygame.event.get():
                if event.type == pygame.QUIT:
                    return False

                elif event.type == pygame.KEYDOWN:
                    if event.key == pygame.K_RETURN:
                        flag = False
                        return True

                    elif event.key == pygame.K_ESCAPE:
                        flag = False
                        return False

            text0 = font.render('Move with arrows', False, (GREEN), (0, 0, 0))
            text1 = font.render('ESC - Exit', False, (GREEN), (0, 0, 0))
            text2 = font.render('P - Pause', False, (GREEN), (0, 0, 0))
            text3 = font.render('Press ENTER to start game', False, (GREEN), (0, 0, 0))
            screen.blit(text0, (50, 120))
            screen.blit(text1, (50, 170))
            screen.blit(text2, (50, 220))
            screen.blit(text3, (50, 300))
            pygame.display.flip()

    def render_exit_view(self, screen, score):
        font = pygame.font.SysFont('dejavuserif', 30, True, True)
        flag = True
        while flag:
            for event in pygame.event.get():
                if event.type == pygame.QUIT:
                    flag = False

                elif event.type == pygame.KEYDOWN:
                    if event.key == pygame.K_ESCAPE:
                        flag = False
                    if event.key == pygame.K_RETURN:
                        return True

            text1 = font.render('Your score: {0}'.format(str(score)), False, (GREEN), (0, 0, 0))
            text2 = font.render('Press ESC to exit', False, (GREEN), (0, 0, 0))
            text3 = font.render('Press ENTER to play again', False, (GREEN), (0, 0, 0))

            screen.blit(text1, (100, 220))
            screen.blit(text2, (50, 270))
            screen.blit(text3, (50, 320))
            pygame.display.flip()


