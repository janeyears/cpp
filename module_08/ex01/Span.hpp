#pragma once
#include <vector>
#include <stdexcept>
#include <cstddef>


class Span {
	public:
	private:
		std::vector<int> _container;
		int _size;
	public:
		Span() = delete;
		Span(unsigned int N);
		Span(const Span &other);
		Span &operator=(const Span &other);
		~Span();
		void addNumber(int value);
		unsigned int shortestSpan();
		unsigned int longestSpan();

		template <typename InputIt>
		void addRange(InputIt begin, InputIt end) {
			size_t rangeSize = std::distance(begin, end);
			if (_container.size() + rangeSize > _size)
				throw std::overflow_error("Container is full. Can't add range of numbers.");
			_container.insert(_container.end(), begin, end);
}
};