f = @(x,y) sqrt(abs(x .* y)) ./ (1 + x.^2 + y.^2);
ezmesh (f, [-3, 3]);