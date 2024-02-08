tx = linspace (-8, 8, 41)';
ty = tx;
[xx, yy] = meshgrid (tx, ty);
r = sqrt (xx .^ 2 + yy .^ 2) + eps;
tz = sin (r) ./ r;
surf (tx, ty, tz), xlabel 'x', ylabel 'y', zlabel 'z', title '$z=\sin(\sqrt{x^2+y^2})/\sqrt{x^2+y^2}$', axis ([-8 8 -8 8 -0.22 1]), axis square, grid off
drawnow ('tikz', 'sombrero.tikz', false, 'sombrero.gp');
