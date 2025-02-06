import rotatescreen
screen = rotatescreen.get_primary_display()
screen.rotate_to(90)
trash = input()
screen.rotate_to(0)
