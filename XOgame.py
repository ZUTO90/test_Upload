import pygame

# Define some colors
BLACK = (0, 0, 0)
WHITE = (255, 255, 255)

# Initialize Pygame
pygame.init()

# Set the screen dimensions
SCREEN_WIDTH = 600
SCREEN_HEIGHT = 600
screen = pygame.display.set_mode((SCREEN_WIDTH, SCREEN_HEIGHT))

# Set the screen title
pygame.display.set_caption("XO Game")

# Create the game grid
grid = [["_", "_", "_"],
        ["_", "_", "_"],
        ["_", "_", "_"]]

# Create the players
player_1 = "X"
player_2 = "O"

# Set the current player
current_player = player_1

# Loop until the game is over
game_over = False
while not game_over:
  # Handle events
  for event in pygame.event.get():
    if event.type == pygame.QUIT:
      game_over = True

  # Clear the screen
  screen.fill(BLACK)

  # Draw the grid lines
  pygame.draw.line(screen, WHITE, (200, 0), (200, 600), 5)
  pygame.draw.line(screen, WHITE, (400, 0), (400, 600), 5)
  pygame.draw.line(screen, WHITE, (0, 200), (600, 200), 5)
  pygame.draw.line(screen, WHITE, (0, 400), (600, 400), 5)

  # Draw the game grid
  for row in range(3):
    for col in range(3):
      if grid[row][col] == player_1:
        # Draw an X
        pygame.draw.line(screen, WHITE, (col * 200 + 20, row * 200 + 20), (col * 200 + 180, row * 200 + 180), 5)
        pygame.draw.line(screen, WHITE, (col * 200 + 180, row * 200 + 20), (col * 200 + 20, row * 200 + 180), 5)
      elif grid[row][col] == player_2:
        # Draw an O
        pygame.draw.circle(screen, WHITE, (col * 200 + 100, row * 200 + 100), 80, 5)

  # Update the screen
  pygame.display.flip()

# Quit Pygame
pygame.quit()
