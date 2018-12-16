#pragma once

// Example 2-3(d): Solving the problems
//
// Precondition:
// - n must not exceed the size of the range
//
template<typename FwdIter>
FwdIter removeNth(FwdIter first, FwdIter last, size_t n)
{
	assert(distance(first, last) >= n);

	advance(first, n);
	if (first != last)
	{
		FwdIter dest = first;
		return copy(++first, last, dest);
	}

	return last;
}