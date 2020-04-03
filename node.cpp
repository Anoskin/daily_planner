#include "node.h"

bool EmptyNode::Evaluate(const Date& date, const string& event) const {
	return true;
}

bool DateComparisonNode::Evaluate(const Date& date, const string& event) const {

	switch (com)
	{
	case Comparison::Equal:
		return date == dat;
	case Comparison::Greater:
		return date > dat;
	case Comparison::GreaterOrEqual:
		return date >= dat;
	case Comparison::Less:
		return date < dat;
	case Comparison::LessOrEqual:
		return date <= dat;
	case Comparison::NotEqual:
		return date != dat;
	default:
		return false;
	}
}

bool EventComparisonNode::Evaluate(const Date& date, const string& event) const {
	switch (com)
	{
	case Comparison::Equal:
		return event == str;
	case Comparison::Greater:
		return event > str;
	case Comparison::GreaterOrEqual:
		return event >= str;
	case Comparison::Less:
		return event < str;
	case Comparison::LessOrEqual:
		return event <= str;
	case Comparison::NotEqual:
		return event != str;
	default:
		return false;
	}
}

bool LogicalOperationNode::Evaluate(const Date& date, const string& event) const {
	return log == LogicalOperation::And ? _left->Evaluate(date, event) && _right->Evaluate(date, event) :
		_left->Evaluate(date, event) || _right->Evaluate(date, event);
}