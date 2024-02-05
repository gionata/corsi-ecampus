function [zero,res,niter,inc]=bisection(fun,a,b,tol,nmax,varargin)
%BISECTION Find function zeros.
%   ZERO=BISECTION(FUN,A,B,TOL,NMAX)
x = [a, (a+b)*0.5, b]; 
[...]
niter = 0; I = (b - a)*0.5;
while I >= tol & niter <= nmax
   niter = niter + 1;
   [...]
end
zero = x(2); x = x(2); res = feval(fun,x,varargin{:});
return
