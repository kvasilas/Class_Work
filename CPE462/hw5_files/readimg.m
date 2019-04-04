function X = readimg(filename,nrows,ncols,precision)
%X = readimg(filename,nrows,ncols,precision)
%
%loads image in binary (RAW) format
%nrows and ncols represent the image height and width,
%and precision represents the data type. See fread
%for more information. 
%
%image is assumed to be stored by rows

fid = fopen(filename,'r');

% image is stored by rows, but is read as an MxN matrix,
% in the column direction. In this case we have M=ncols,
% N=nrows
% precision usually is set to 'uchar'

[X,count] = fread(fid,[ncols,nrows],precision);

if (count ~= (nrows*ncols) )
  error('dimensions dont match file contents---load aborted');
end
fclose(fid);     

%take the transpose of X, to get correct row-column orientation
%of image
X=X';
%imshow(X/255,256);
image(X);
colormap(gray(256));

