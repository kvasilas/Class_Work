function X = procjpg(in_filename, out_filename)
% X = readjpg(in_filename, out_filename)
% Example usage: x=procjpg('graphic1.jpg','graphic2.raw')
% 1. This function reads in a JPEG file and store it in RGB, 
% 2. Display it in color 
% 3. Convert it to YCbCr
% 4. Separate the Y component and display its size (which will 
%    be used in reading and writing in RAW files).
% 5. Store the Y component into a RAW file that cab be read by
%    "imageproc.c".


X = imread(in_filename,'jpg');

image(X);

Y=rgb2ycbcr(X);

y1=Y(:,:,1);

size(y1)

f=fopen(out_filename,'wb');
fwrite(f,y1,'uchar');
fclose(f);


