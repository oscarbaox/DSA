#include <criterion/criterion.h>

#include "scheduler.hpp"

Test(first_algorithm, detects_no_conflict) {
	const MeetingTimes meetings = {
		{1, {9.0, 10.0}},
		{2, {10.0, 11.0}},
		{3, {13.0, 14.5}},
	};

	cr_assert_eq(firstAlgorithm(meetings), EXIT_SUCCESS);
}

Test(first_algorithm, detects_overlapping_meetings) {
	const MeetingTimes meetings = {
		{1, {9.0, 10.5}},
		{2, {10.0, 11.0}},
	};

	cr_assert_eq(firstAlgorithm(meetings), EXIT_FAILURE);
}

Test(first_algorithm, allows_meetings_that_only_touch) {
	const MeetingTimes meetings = {
		{1, {8.0, 9.0}},
		{2, {9.0, 10.0}},
	};

	cr_assert_eq(firstAlgorithm(meetings), EXIT_SUCCESS);
}

Test(second_algorithm, detects_no_conflict_when_input_is_unsorted) {
	const MeetingTimes meetings = {
		{1, {13.0, 14.0}},
		{2, {9.0, 10.0}},
		{3, {11.0, 12.0}},
	};

	cr_assert_eq(secondAlgorithm(meetings), EXIT_SUCCESS);
}

Test(second_algorithm, detects_overlapping_meetings) {
	const MeetingTimes meetings = {
		{1, {13.0, 15.0}},
		{2, {9.0, 10.0}},
		{3, {9.5, 11.0}},
	};

	cr_assert_eq(secondAlgorithm(meetings), EXIT_FAILURE);
}

Test(second_algorithm, allows_meetings_that_only_touch) {
	const MeetingTimes meetings = {
		{1, {13.0, 14.0}},
		{2, {9.0, 10.0}},
		{3, {10.0, 11.0}},
	};

	cr_assert_eq(secondAlgorithm(meetings), EXIT_SUCCESS);
}
