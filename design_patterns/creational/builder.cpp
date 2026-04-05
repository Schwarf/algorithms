//
// Created by andreas on 05.04.26.
//

#include <iostream>
#include <string>
#include <vector>

class SqlQuery {
private:
    std::string selectClause;
    std::string fromClause;
    std::string whereClause;
    std::string orderByClause;

public:
    std::string getSelectClause() const {
        return selectClause;
    }

    std::string getFromClause() const {
        return fromClause;
    }

    std::string getWhereClause() const {
        return whereClause;
    }

    std::string getOrderByClause() const {
        return orderByClause;
    }

    void setSelectClause(const std::string& select) {
        selectClause = select;
    }

    void setFromClause(const std::string& from) {
        fromClause = from;
    }

    void setWhereClause(const std::string& where) {
        whereClause = where;
    }

    void setOrderByClause(const std::string& orderBy) {
        orderByClause = orderBy;
    }

    std::string toString() const {
        std::string query = selectClause + " " + fromClause;

        if (!whereClause.empty()) {
            query += " " + whereClause;
        }

        if (!orderByClause.empty()) {
            query += " " + orderByClause;
        }

        query += ";";
        return query;
    }
};

class SqlQueryBuilder {
private:
    SqlQuery query;

public:
    SqlQueryBuilder& select(const std::string& columns) {
        query.setSelectClause("SELECT " + columns);
        return *this;
    }

    SqlQueryBuilder& from(const std::string& table) {
        query.setFromClause("FROM " + table);
        return *this;
    }

    SqlQueryBuilder& where(const std::string& condition) {
        query.setWhereClause("WHERE " + condition);
        return *this;
    }

    SqlQueryBuilder& orderBy(const std::string& column) {
        query.setOrderByClause("ORDER BY " + column);
        return *this;
    }

    SqlQuery build() {
        return query;
    }
};

int main() {
    SqlQuery query = SqlQueryBuilder()
        .select("name, age")
        .from("users")
        .where("age >= 18")
        .orderBy("name")
        .build();

    std::cout << "Generated SQL query:\n";
    std::cout << query.toString() << '\n';

    return 0;
}