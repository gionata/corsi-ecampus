function [zero,res,niter,inc]=bisection(fun,a,b,tol,nmax,varargin)
%BISECTION Find function zeros.
%   ZERO=BISECTION(FUN,A,B,TOL,NMAX) tries to find a zero ZERO of the continuous 
%   function FUN in the interval [A,B] using the bisection method. FUN accepts 
%   real scalar input x and returns a real scalar value. If the search fails 
%   an errore message is displayed. FUN can also be an inline object.
%   ZERO=BISECTION(FUN,A,B,TOL,NMAX,P1,P2,...) passes parameters P1,P2,...
%   to function: FUN(X,P1,P2,...).
%
%   [ZERO,RES,NITER]= BISECTION(FUN,...) returns the value of the residual in ZERO
%   and the iteration number at which ZERO was computed.
%
%   [ZERO,RES,NITER,INC]= BISECTION(FUN,...) returns a vector INC with the absolute value of the
%   differences between successive approximations (increments).

%   A.Quarteroni, F.Saleri, Introduction to the Scientific Computing, 2003

x = [a, (a+b)*0.5, b]; 
inc = x(2);
fx = feval(fun,x,varargin{:});
if fx(1)*fx(3)>0
    error(' The sign of FUN at the extrema of the interval must be different');
elseif fx(1) == 0
    zero = a; res = 0; niter = 0;
    return
elseif fx(3) == 0
    zero = b; res = 0; niter = 0;
    return
end 
niter = 0; 
I = (b - a)*0.5;
while I >= tol & niter <= nmax
   niter = niter + 1;
   if sign(fx(1))*sign(fx(2)) < 0
      x(3) = x(2); 
      x(2) = x(1)+(x(3)-x(1))*0.5;
      fx = feval(fun,x,varargin{:}); 
      I = (x(3)-x(1))*0.5;
   elseif sign(fx(2))*sign(fx(3)) < 0
      x(1) = x(2); 
      x(2) = x(1)+(x(3)-x(1))*0.5;
      fx = feval(fun,x,varargin{:}); 
      I = (x(3)-x(1))*0.5;
   else  
       x(2) = x(find(fx==0)); 
       I = 0; 
   end
   inc(end) = abs(inc(end) - x(2));
   inc(end+1) = x(2);
end
inc(end) = [];
if niter > nmax
    fprintf(['bisection stopped without converging to the desired tolerance',...
    'because the maximum number of iterations was reached\n']);
end

zero = x(2);
x = x(2); res = feval(fun,x,varargin{:});
return
