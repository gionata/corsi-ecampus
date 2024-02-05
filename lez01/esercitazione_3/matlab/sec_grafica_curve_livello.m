[x,y] = meshgrid(-1:.01:1);
z = x.*exp(-x.^2-y.^2);
[c,h]=contour(x,y,z);
h = clabel(c,h);
set(h,'BackgroundColor',[1 1 .6]);
