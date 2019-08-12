#include <stdlib.h>
#include <stdio.h>

struct s_node {
	int           value;
	struct s_node *right;
	struct s_node *left;
};

struct s_node *convert_bst(struct s_node *bst)
{
	struct s_node *ret;

	if (!bst)
		return (NULL);
	ret = convert_bst(bst->left);
	bst->right = convert_bst(bst->right);
	if (ret)
	{
		ret->left->right = bst;
		bst->left = ret->left;
	}
	else
		ret = bst;
	if (bst->right)
	{
		bst->right->left->right = ret;
		ret->left = bst->right->left;
		bst->right->left = bst;
	}
	else
	{
		bst->right = ret;
		ret->left = bst;
	}
	return (ret);
}

//---------------------------------------------------------
#include <stdio.h>

void	print_list(struct s_node *cur)
{
	struct s_node *first = cur;

 	printf("%d", cur->value);
 	cur = cur->right;

 	while (cur != first)
 	{
 		printf(" -> %d", cur->value);
 		cur = cur->right;
 	}
 	printf("\n");
}

#define NODE(v, r, l) &(struct s_node){v, l, r}
int	main(void)
{
 	struct s_node *root = NODE(10,
 		NODE(5,
 			NODE(4,
 				NODE(2,
 					NODE(1, 0, 0),
 					NODE(3, 0, 0)
					),
 				0
				),
 			NODE(7,
 				NODE(6, 0, 0),
 				NODE(8, 0, 0)
 				)
 			),
 		NODE(12,
 			NODE(11, 0, 0),
 			NODE(15,
 				0,
 				NODE(17,
 					NODE(16, 0, 0),
 					NODE(20, 0, 0)
 					)
 				)
			)
 		);
 	print_list(convert_bst(root));
}
