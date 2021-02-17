from PIL import Image, ImageDraw
im = Image.open(r"/home/kcvas/Documents/Class_Work/CPE592/pictures/brick.jpeg")  

i2=ImageDraw.Draw(im)
i2.text((28, 36), "KC VASILAS", fill=(0, 0, 0)) 

im.save("kc_brick.jpeg")

im.show()
