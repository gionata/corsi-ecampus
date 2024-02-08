## Copyright (C) 2012 Gionata Massi
## based on Octave rref
## GNU General Public License

## -*- texinfo -*-
## @deftypefn {Function File} {[@var{r}, @var{k}] =} gauss (@var{a}, @var{tol})
##
## Returns the Gauss reduced form of @var{a}.  @var{tol} defaults
## to @code{eps * max (size (@var{a})) * norm (@var{a}, inf)}.
##
## Called with two return arguments, @var{k} returns the vector of
## "bound variables", which are those columns on which elimination 
## has been performed.
##
## @end deftypefn

## Author: Gionata Massi <gionata.massi@uniecampus.it>
##         based on
##		   Paul Kienzle <pkienzle@users.sf.net> rref
##         (based on a anonymous source from the public domain)

function [A, k] = gauss (A, tolerance)

  if (nargin < 1 || nargin > 2)
    print_usage ();
  endif

  if (ndims (A) > 2)
    error ("gauss: expecting matrix argument");
  endif

  [rows, cols] = size (A);

  if (nargin < 2)
    if (isa (A, "single"))
      tolerance = eps ("single") * max (rows, cols) * norm (A, inf ("single"));
    else
      tolerance = eps * max (rows, cols) * norm (A, inf);
    endif
  endif

  used = zeros (1, cols);
  r = 1;
  for c = 1:cols
    ## Find the pivot row
    // [m, pivot] = max (abs (A(r:rows,c)));
	rr = c
	while (A(rr, c) <= tolerance)
		tmp = A(rr+1, :);
		A(rr+1, :) = A(rr, :);
		A(rr, :) = tmp;
	end
    pivot = r + pivot - 1;

    if (m <= tolerance)
      ## Skip column c, making sure the approximately zero terms are
      ## actually zero.
      A (r:rows, c) = zeros (rows-r+1, 1);
    else
      ## keep track of bound variables
      used (1, c) = 1;

      ## Swap current row and pivot row
      ### A ([pivot, r], c:cols) = A ([r, pivot], c:cols);

      ## Normalize pivot row
      ## A (r, c:cols) = A (r, c:cols) / A (r, c); ## Gionata Massi

      ## Eliminate the current column
      ridx = [1:r-1, r+1:rows];
      A (ridx, c:cols) = A (ridx, c:cols) - A (ridx, c) * A(r, c:cols);

      ## Check if done
      if (r++ == rows)
	break;
      endif
    endif
  endfor
  k = find (used);

endfunction
