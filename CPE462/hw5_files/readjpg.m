function X = readjpg(filename)
%X = readjpg(filename)
X = imread(filename,'jpg');

image(X);

