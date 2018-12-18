#pragma once

#include <cassert>

// Example 2-3(d): Solving the problems
//
// Precondition:
// - n must not exceed the size of the range
//
// The function distance(first, last) must be callable.
template<typename FwdIter>
FwdIter removeNth(FwdIter first, FwdIter last, size_t n)
{
	assert(distance(first, last) >= static_cast<typename std::iterator_traits<FwdIter>::difference_type>(n));

	advance(first, n);
	if (first != last)
	{
		FwdIter dest = first;
		return copy(++first, last, dest);
	}

	return last;
}