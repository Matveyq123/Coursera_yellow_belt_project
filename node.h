#pragma once
#include "date.h"
#include<memory>

enum class LogicalOperation {
	And,
	Or
};
enum class Comparison {
    Less,
	LessOrEqual,
	Greater,
	GreaterOrEqual,
	Equal,
	NotEqual
};
class Node {
public:
	virtual bool Evaluate(const Date& date, const std::string event) const = 0;
};
class EmptyNode : public Node {
public:
	bool Evaluate(const Date& date, const std::string event) const override;
};
class DateComparisonNode :public Node {
public:
	DateComparisonNode(const Comparison& cmp, const Date& date);
	bool Evaluate(const Date& date, const std::string event) const override;
private:
	const Comparison cmp_;
	const Date date_;
};
class EventComparisonNode :public Node {
public:
	EventComparisonNode(const Comparison& cmp, const std::string& event);
	bool Evaluate(const Date& date, const std::string event) const override;
private:
	const Comparison cmp_;
	const std::string event_;
};
class LogicalOperationNode :public Node {
public:
	LogicalOperationNode(const LogicalOperation& logical_op, const std::shared_ptr<const Node>& left, const std::shared_ptr<const Node>& right);
	bool Evaluate(const Date& date, const std::string event) const override;
private:
	const LogicalOperation logical_op_;
	const std::shared_ptr<const Node> left_, right_;

};
