fx = @(s,t) cos (s) .* cos(t);
fy = @(s,t) sin (s) .* cos(t);
fz = @(s,t) sin (t);
ezmesh (fx, fy, fz, [-pi,pi,-pi/2,pi/2], 20);