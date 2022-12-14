[![Open in Visual Studio Code](https://classroom.github.com/assets/open-in-vscode-c66648af7eb3fe8bc4f294546bfd86ef473780cde1dea487d3c4ff354943c9ae.svg)](https://classroom.github.com/online_ide?assignment_repo_id=7966244&assignment_repo_type=AssignmentRepo)
# A03 - Priority Queue

## Learning Outcomes

- Practice with lists
- Building complex data structures using lists
- Incremental development

## Tasks

You saw how a list of integers can be used to implement a set of integers in A2. In this lab, you will implement another important data structure using a list.

Let's first discuss the use-case. Many a times, we create sequences with elements that have a sense of priority in them. For instance, for admission to a college, students rank in the entrance exam can be a criteria for priority (and if there is a clash, there can be additional critera). Imagine a large hall where students are coming in with their rank certificate. Who is the first one to be called? The one with the topmost rank. Then the next rank, and then the next, and so on.

Even if a student with rank 10 was the first to arrive, they will call the student with rank 1 first. So the criteria for processing the elements is not the time of arrival (like a queue for movie tickets), but some value that the element holds.

Such queues are called priority queues.

You will implement a priority queue of integers using a list of integers.

There are obviously more than one ways of implementing this, but you will implement it a certain way here, so read carefully.

### Task 0

Take a look at the given `struct priority_queue` and the given `to_string` function. It is very similar to the definition of `set` in A2. But make sure you understand the description of the `struct`.

- First, elements are *stored* in a specific order, and the next element is always removed from the front of the list (index 0).
- Second, duplicates are allowed, unlike sets. If there are two elements with the same value which are eligible to be removed next, still the one at index 0 will be removed.

### Tasks 1-4

Implement the following functions to match their descriptions:

- `queue_size`
- `index_to_insert`
- `insert_in_order`
- `remove_next`

Add at least two test cases for each function using `cp::expect`.

## Food for thought

Do not modify your code once you are done with the tasks 1-4. This section is just a food for thought. it will not affect your marks for this assignment. But this will help you understand some advanced concepts better.

Suppose we want to remove the next 'largest' from the priority queue instead of the smallest. What changes would you make to your code?

Suppose the criteria is something more complex - like with real use case of admissions based on ranks in entrace exams: to break the ties, they use some combination of PCM marks, 12th std. total, 10th std. marks, etc. How easy or difficult to make such changes?
