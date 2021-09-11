#include "push_swap.h"

static void		check_duplicates(t_frame *frame)
{
	t_stack		*slow;
	t_stack		*fast;

	slow = frame->a;
	while (slow != frame->a->prev)
	{
		fast = slow->next;
		while (fast != frame->a)
		{
			if (slow->num == fast->num)
				push_swap_error(frame);
			fast = fast->next;
		}
		slow = slow->next;
	}
}