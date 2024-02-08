function fib = fib_recursive(n)
% fib_recursive.m
% Given an integers n, compute the n-th Fibonacci number.
if (n == 1 || n == 2)
	fib = 1;
else
	fib = fib_recursive(n - 1) + ...
	      fib_recursive(n - 2);
end
return
