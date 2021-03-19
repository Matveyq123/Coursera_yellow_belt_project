#include"node.h"

bool EmptyNode::Evaluate(const Date& date, const std::string event) const {
	return true;
}
DateComparisonNode::DateComparisonNode(const Comparison& cmp, const Date& date) : cmp_(cmp), date_(date) {}
bool DateComparisonNode::Evaluate(const Date& date, const std::string event) const {
	if (cmp_ == Comparison::Equal) {
		return date == date_;
	}
	if (cmp_ == Comparison::Less) {
		return date < date_;
	}
	if (cmp_ == Comparison::LessOrEqual) {
		return date <= date_;
	}
	if (cmp_ == Comparison::GreaterOrEqual) {
		return date >= date_;
	}
	if (cmp_ == Comparison::Greater) {
		return date > date_;
	}
		return date != date_;
}
EventComparisonNode::EventComparisonNode(const Comparison& cmp, const std::string& event) : cmp_(cmp), event_(event) {}
bool EventComparisonNode::Evaluate(const Date& date, const std::string event) const {
	if (cmp_ == Comparison::Equal) {
		return event == event_;
	}
	if (cmp_ == Comparison::Less) {
		return event < event_;
	}
	if (cmp_ == Comparison::LessOrEqual) {
		return event <= event_;
	}
	if (cmp_ == Comparison::GreaterOrEqual) {
		return event >= event_;
	}
	if (cmp_ == Comparison::Greater) {
		return event > event_;
	}
	return event != event_;
}

LogicalOperationNode::LogicalOperationNode(const LogicalOperation& logical_op, const std::shared_ptr<const Node>& left, const std::shared_ptr<const Node>& right) :logical_op_(logical_op), left_(left), right_(right) {}
bool LogicalOperationNode::Evaluate(const Date& date, const std::string event) const {
	if (logical_op_ == LogicalOperation::Or) {
		return left_->Evaluate(date, event) || right_->Evaluate(date, event);
	}
		return left_->Evaluate(date, event) && right_->Evaluate(date, event);
}
