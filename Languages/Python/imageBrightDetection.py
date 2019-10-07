from PIL import Image

img_path = 'your-image-path-goes-here'

imag = Image.open(img_path)
imag = imag.convert('RGB')

# Pixel coordinates
X, Y = 50, 50

# Here R, G and B variables received color tones
RGB = imag.getpixel((X, Y))
R, G, B = RGB

# Bright calculation: 0 for non bright picture, therefore a dark image, until 255 to a shiny image
brightness = sum([R, G, B]) / 3
print(brightness)
