#pragma once

#include "date.h"
#include <memory>
#include <string>

enum class Comparison {
	Less,
	LessOrEqual,
	Greater,
	GreaterOrEqual,
	Equal,
	NotEqual,
};

enum class LogicalOperation {
	And,
	Or,
};


struct Node
{
	virtual bool Evaluate(const Date& date, const string& event) const = 0;
};

struct EmptyNode : public Node {
public:
	bool Evaluate(const Date& date, const string& event) const override;

};

struct DateComparisonNode : public Node {
public:
	DateComparisonNode(const Comparison& cmd, const Date& date) :
		com(cmd), dat(date) {}
	bool Evaluate(const Date& date, const string& event) const override;

private:
	const Comparison com;
	const Date dat;
};

struct EventComparisonNode : public Node {
public:
	EventComparisonNode(const Comparison& cmd, const string& val) :
		com(cmd), str(val) {}
	bool Evaluate(const Date& date, const string& event) const override;

private:
	const Comparison com;
	const string str;
};

struct LogicalOperationNode : public Node {
public:
	LogicalOperationNode(const LogicalOperation& logical, shared_ptr< Node> lhs,
		shared_ptr< Node> rhs) : log(logical), _left(lhs), _right(rhs) {}

	bool Evaluate(const Date& date, const string& event) const override;

private:
	const LogicalOperation log;
	shared_ptr< Node> _left, _right;
};