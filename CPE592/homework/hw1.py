# Kirk Vasilas
#
# CPE 592
# Homework 1
#
# 2/11/2021

# usage python3 hw1.py image_name stego_key
# image must be in directory or provide full path

import sys
from PIL import Image

def set_bit(old_byte, new_bit, scheme):
    if scheme == "lsb":
        b = list(bin(old_byte))
        b[-1] = new_bit
        return int(''.join(b),2)
    else:
        b = list(format(old_byte, 'b'))
        b[0] = new_bit
        try:
            b = int(''.join(b),2)
            return b
        except:
            return old_byte

def encode_image(raw_img, payload, scheme):
    temp = raw_img.copy()
    if scheme == "lsb":
        joinstr=''
    else:
        joinstr=' '
    bitstream = iter(joinstr.join(format(x, 'b') for x in bytearray(payload, 'utf8')))
    img_area = raw_img.size[0] * raw_img.size[1]
    try:
        #iterate through pixles from len of the key to the end
        for a in range(stego_key, img_area):
            i = int(a / raw_img.size[0])
            j = a % raw_img.size[0]
            #grab current pixel values
            r,g,b = raw_img.getpixel((j,i))
            #encoded pixel values
            rb = next(bitstream)
            r = set_bit(r, rb, scheme)
            gb = next(bitstream)
            g = set_bit(g, gb, scheme)
            bb = next(bitstream)
            b = set_bit(b, bb, scheme)
            #re write pixel with the new encoded data
            temp.putpixel((j,i),(r,g,b))
    except:
        print(scheme, "Encoded.", sep=" ")
    
    temp.save("kvas_hw1_"+scheme+".jpg", "jpeg")
    return

if __name__ == '__main__':
    #Global Var
    img_loc = sys.argv[1]
    stego_key = sum(bytearray(sys.argv[2], "utf8"))
    payload = "Kirk_Vasilas"
    
    #read in image
    raw_image = Image.open(img_loc,'r')
    #encode LSB and MSB
    encode_image(raw_image, payload, "lsb")
    encode_image(raw_image, payload, "msb")    