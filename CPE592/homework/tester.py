import sys
from PIL import Image

def decode(raw_img, payload, scheme):
    temp = raw_img.copy()
    if scheme == "lsb":
        joinstr=''
    else:
        joinstr=' '
    bitstream = iter(joinstr.join(format(x, 'b') for x in bytearray(payload, 'utf8')))
    
    for a in range(stego_key, raw_img.size[0] * raw_img.size[1]):
            
        i = int(a / raw_img.size[0])
        j = a % raw_img.size[0]
        
        print(raw_img.getpixel((j,i)))