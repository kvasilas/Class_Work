% hw0_1.m
Fs = 256;
t = (1:256)/Fs;
s=sin(2*pi*10*t);
figure(1);
plot(t,s);
w=ones(256,1)*s;
figure(2);
image((w+1)*256/2);
truesize;
colormap(gray(256));



