import numpy as np
from PIL import Image

# Load the extracted bytes (adjust the file path as needed)
print("looking for rodata.bin to read from")
print("if you have not dumped rodata, you do so like the following command:")
print("objcopy -O binary --only-section=.rodata EXAMPLE.elf rodata.bin")

with open("rodata.bin", "rb") as f:
    data = f.read()

# For OLED displays, data is typically organized as:
# - Each byte represents 8 vertical pixels
# - Pages/rows of bytes represent horizontal segments

# Assuming 128x64 display (common OLED size)
width, height = 128, 160
pages = height // 8

# Create an empty image
img = Image.new("1", (width, height), color=0)
pixels = img.load()

# Convert the data to image
for page in range(pages):
    for x in range(width):
        if page * width + x < len(data):
            byte = data[page * width + x]
            for bit in range(8):
                y = page * 8 + bit
                pixels[x, y] = (byte >> bit) & 1

# Save the image
img.save("extracted_image.png")
print("Image saved as extracted_image.png")
img.show()
