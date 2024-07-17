from PIL import Image

im = Image.open('shirtificate.png')
print(im.format, im.size, im.mode)
