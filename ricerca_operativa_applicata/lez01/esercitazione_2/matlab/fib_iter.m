function fib = fib_iter(n)
% fib_iter.m
% Given an integers n, compute the n-th Fibonacci number.
seq=ones(n,1);
for k=3:n
	seq(k) = seq(k - 1) + seq(k - 2);
end
fib = seq(n);
return
