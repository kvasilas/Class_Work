% cd c:\hman\cpe462
f=fopen('..\..\images\lenna.512','r');
x=fread(f,[512,512],'uchar');
imshow(x'/255,256);
xx=x(225:288,225:288);
y=x;
y(225:288,225:288)=zeros(64,64);
imshow(y'/255,256);
figure(2);
imshow(xx'/255,256);
figure(3);
meshz(xx);
