#include <cp/cp.hpp>


/**
 * @brief Represents a priority queue of integers. Elements are always stored in a non-decreasing order. You can only remove the smallest integer from it. Duplicates are allowed.
 * 
 * Example:
 * [1] is a priority queue. You can only remove `1` from it.
 * [1, 4, 7] is a priority queue. You can only remove `1` from it.
 * [4, 7, 1] is *not* a priority queue.
 * 
 */
struct priority_queue {
  cp::list_int value;
};

/**
 * @brief String represenatation of the priority queue.
 * 
 */
cp::string to_string(priority_queue* pq) {
  return pq->value.to_string();
}


/**
 * @brief Reports the number of elements in the priority queue.
 * 
 * @retval 0 queue_size([])
 * @retval 2 queue_size([1, 2])
 * 
 */
int queue_size(priority_queue* pq) {
  return pq->value.size();
}


/**
 * @brief Computes the index where `x` can be inserted in the given priority queue, so that its property is maintained.
 * 
 * @retval 0 index_to_insert([], 4)
 * @retval 0 index_to_insert([4], 2)
 * @retval 1 index_to_insert([4, 6], 5)
 * @retval 2 index_to_insert([4, 6], 8)
 */
int index_to_insert(priority_queue* pq, int x) {
  int i = 0;
  int index = 0;
  while(i<queue_size(pq)){
    if(x>pq->value[i]){
      index++;
    }
    i++;
  }
  return index;
}


/**
 * @brief Inserts `x` in the given priority queue such that its propeerty is maintained.
 * 
 * @retval insert_in_order([], 4) -> [4]
 * @retval insert_in_order([4], 6) -> [4, 6]
 * @retval insert_in_order([4, 6], 2) -> [2, 4, 6]
 */
void insert_in_order(priority_queue* pq, int x) {
  pq->value.insert_at(index_to_insert(pq,x),x);
}


/**
 * @brief Removes and returns the smallest number in the given non-empty priority queue. The property holds after the operation.
 * 
 * @retval 4 remove_next([4]) -> []
 * @retval 4 remove_next([4, 6]) -> [6]
 * 
 */
int remove_next(priority_queue* pq) {
  return pq->value.remove_from(0);
}

int main() {
  priority_queue* ranks = new priority_queue();

  cp::expect(0 == index_to_insert(ranks, 5), "5 should be inserted at index 0");

  insert_in_order(ranks, 4);
  cp::expect(1 == queue_size(ranks), "ranks has one element");
  cp::expect("[4]" == to_string(ranks), "ranks is [4]");

  cp::expect(4 == remove_next(ranks), "4 is removed");
  cp::expect("[]" == to_string(ranks), "ranks is empty after removing 4");

  cp::expect(0 == index_to_insert(ranks, 5), "5 should be inserted at index 0");

  insert_in_order(ranks, 5);
  cp::expect(1 == queue_size(ranks), "ranks has one element after inserting 5");
  cp::expect("[5]" == to_string(ranks), "ranks is [5] after inserting 5");

  insert_in_order(ranks, 7);
  cp::expect("[5, 7]" == to_string(ranks), "ranks is [5, 7] after inserting 7");

  insert_in_order(ranks, 2);
  cp::expect("[2, 5, 7]" == to_string(ranks), "ranks is [2, 5, 7] after inserting 2");

  cp::expect(2 == remove_next(ranks), "2 is removed");
  cp::expect("[5, 7]" == to_string(ranks), "ranks is [5, 7] after removing 2");

  priority_queue* ranks2 = new priority_queue();

  cp::expect(0 == index_to_insert(ranks2, 7), "7 should be inserted at index 0");

  insert_in_order(ranks2, 2);
  cp::expect(1 == queue_size(ranks2), "ranks2 has one element");
  cp::expect("[2]" == to_string(ranks2), "ranks2 is [2]");

  cp::expect(1 == index_to_insert(ranks2, 7), "7 should be inserted at index 1");

  insert_in_order(ranks2, 7);
  cp::expect(2 == queue_size(ranks2), "ranks2 has two elements");
  cp::expect("[2, 7]" == to_string(ranks2), "ranks2 is [2, 7]");

  cp::expect(2 == remove_next(ranks2), "2 is removed");
  cp::expect("[7]" == to_string(ranks2), "ranks2 is [7] after removing 2");

  cp::expect(7 == remove_next(ranks2), "7 is removed");
  cp::expect("[]" == to_string(ranks2), "ranks2 is empty after removing 7");

  cp::expect(0 == queue_size(ranks2), "ranks2 is empty");

  return 0;
}
