webcamlist
cam = webcam('HP Truevision HD');
frame = snapshot(cam);
image(frame);
IMG=frame
size(IMG)
r=IMG(:,:,1); g=IMG(:,:,2); b=IMG(:,:,3);
Y=r*0.299 + g*0.587 + b*0.114
dispimg(Y);