#pragma once
#include <map>
class Btc {
	public:
		Btc(const std::string &dbFile);
		Btc (const Btc &other) = default;
		Btc &operator=(const Btc &other) = default;
		~Btc();

		void processInput(const std::string &file);

	private:
		std::map<std::string, double> _data;
		bool loadDatabase(const std::string &dbFile);
		bool isValidDate(const std::string &date) const;
		bool isNumber(const std::string &str) const;
		std::string trim(const std::string &s) const;
		bool findRate(const std::string &date, double &rate) const;
};