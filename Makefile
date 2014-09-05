GMOCK_DIR=/home/syl/developer/gmock-1.6.0
GTEST_DIR=/home/syl/developer/gtest-1.6.0

ADT_DIR=./abstract_data_types
TESTCASE_DIR=./unit_test
OTHER_DIR=./other

CXXFLAGS=-Wall -g -O0

TARGET = test
SRC_FILES = path_sum.cpp \
			merge_two_sorted_lists.cpp \
			$(OTHER_DIR)/max_sum_of_subarray.cpp \
			$(OTHER_DIR)/max_stack.cpp \
			$(OTHER_DIR)/max_queue.cpp \
			max_depth_of_binary_tree.cpp \
			linked_list_cycle.cpp \
			add_binary.cpp \
			$(OTHER_DIR)/triangle.cpp \
			$(OTHER_DIR)/the_disjoint_set.cpp \
			single_number.cpp \
			same_tree.cpp \
			reverse_integer.cpp \
			remove_duplicates_from_sorted_array.cpp \
			$(OTHER_DIR)/quick_sort.cpp \
			populating_next_right_pointers_in_each_node.cpp \
			roman_to_integer.cpp \
			implement_strstr.cpp \
			two_sum.cpp \
			longest_substring_without_repeating_char.cpp \
			multiply_strings.cpp \
			gray_code.cpp \
			plus_one.cpp \
			rotate_image.cpp \
			jump_game.cpp \
			jump_game_II.cpp \
			sort_colors.cpp \
			climbing_stairs.cpp \
			best_time_to_buy_and_sell_stock.cpp \
			best_time_to_buy_and_sell_stock_II.cpp \
			unique_binary_search_trees.cpp \
			binary_tree_inorder_traversal.cpp \
			binary_tree_postorder_traversal.cpp \
			binary_tree_preorder_traversal.cpp \
			single_number_II.cpp \
			search_insert_position.cpp \
			$(ADT_DIR)/binary_tree_with_link.cpp \
			$(ADT_DIR)/singly_linked_list.cpp \
			$(ADT_DIR)/binary_tree.cpp \
			maximum_subarray.cpp \
			integer_to_roman.cpp \
			remove_element.cpp \
			n_queens.cpp \
			n_queens_ii.cpp \
			balanced_binary_tree.cpp \
			merge_sorted_array.cpp \
			unique_paths.cpp \
			convert_sorted_array_to_binary_search_tree.cpp \

SRC_TEST_FILES = $(TESTCASE_DIR)/multiply_strings_test.cpp \
				 $(TESTCASE_DIR)/merge_two_sorted_lists_test.cpp \
				 $(OTHER_DIR)/max_sum_of_subarray_test.cpp \
				 $(OTHER_DIR)/max_stack_test.cpp \
				 $(OTHER_DIR)/max_queue_test.cpp \
				 $(TESTCASE_DIR)/max_depth_of_binary_tree_test.cpp \
				 $(TESTCASE_DIR)/longest_substring_without_repeating_char_test.cpp \
				 $(TESTCASE_DIR)/add_binary_test.cpp \
				 $(TESTCASE_DIR)/two_sum_test.cpp \
				 $(OTHER_DIR)/triangle_test.cpp \
				 $(OTHER_DIR)/the_disjoint_set_test.cpp \
				 $(TESTCASE_DIR)/single_number_test.cpp \
				 $(TESTCASE_DIR)/same_tree_test.cpp \
				 $(TESTCASE_DIR)/reverse_integer_test.cpp \
				 $(TESTCASE_DIR)/remove_duplicates_from_sorted_array_test.cpp \
				 $(OTHER_DIR)/quick_sort_test.cpp \
				 $(TESTCASE_DIR)/path_sum_test.cpp \
				 $(TESTCASE_DIR)/populating_next_right_pointers_in_each_node_test.cpp \
				 $(TESTCASE_DIR)/linked_list_cycle_test.cpp \
				 $(TESTCASE_DIR)/roman_to_integer_test.cpp \
				 $(TESTCASE_DIR)/implement_strstr_test.cpp \
				 $(TESTCASE_DIR)/gray_code_test.cpp \
				 $(TESTCASE_DIR)/plus_one_test.cpp \
				 $(TESTCASE_DIR)/rotate_image_test.cpp \
				 $(TESTCASE_DIR)/jump_game_test.cpp \
				 $(TESTCASE_DIR)/jump_game_II_test.cpp \
				 $(TESTCASE_DIR)/sort_colors_test.cpp \
				 $(TESTCASE_DIR)/climbing_stairs_test.cpp \
				 $(TESTCASE_DIR)/best_time_to_buy_and_sell_stock_test.cpp \
				 $(TESTCASE_DIR)/best_time_to_buy_and_sell_stock_II_test.cpp \
				 $(TESTCASE_DIR)/unique_binary_search_trees_test.cpp \
				 $(TESTCASE_DIR)/binary_tree_xorder_traversal_test.cpp \
				 $(TESTCASE_DIR)/single_number_II_test.cpp \
				 $(TESTCASE_DIR)/search_insert_position_test.cpp \
				 $(ADT_DIR)/binary_tree_with_link_test.cpp \
				 $(ADT_DIR)/singly_linked_list_test.cpp \
				 $(ADT_DIR)/binary_tree_test.cpp \
				 $(TESTCASE_DIR)/maximum_subarray_test.cpp \
				 $(TESTCASE_DIR)/integer_to_roman_test.cpp \
				 $(TESTCASE_DIR)/remove_element_test.cpp \
				 $(TESTCASE_DIR)/n_queens_test.cpp \
				 $(TESTCASE_DIR)/balanced_binary_tree_test.cpp \
				 $(TESTCASE_DIR)/merge_sorted_array_test.cpp \
				 $(TESTCASE_DIR)/unique_paths_test.cpp \
				 $(TESTCASE_DIR)/convert_sorted_array_to_binary_search_tree_test.cpp \

OBJ_FILES = $(patsubst %.cpp,%.o,$(SRC_FILES) )
OBJ_TEST_FILES = $(patsubst %.cpp,%.o,$(SRC_TEST_FILES) )

all: $(OBJ_FILES) $(OBJ_TEST_FILES)
	g++ -I${GTEST_DIR}/include -I${GTEST_DIR} -I${GMOCK_DIR}/include \
		-I${GMOCK_DIR} -c ${GTEST_DIR}/src/gtest-all.cc
	g++ -I${GTEST_DIR}/include -I${GTEST_DIR} -I${GMOCK_DIR}/include \
		-I${GMOCK_DIR} -c ${GMOCK_DIR}/src/gmock-all.cc
	ar -rv libgmock.a gtest-all.o gmock-all.o
	g++ -I${GTEST_DIR}/include -I${GMOCK_DIR}/include -c main.cpp
	g++ -o $(TARGET) $(OBJ_FILES) $(OBJ_TEST_FILES) main.o libgmock.a -lpthread

$(OBJ_FILES):%.o:%.cpp
	g++ ${CXXFLAGS} -I${ADT_DIR} -o $@ -c $<

$(OBJ_TEST_FILES):%.o:%.cpp
	g++ ${CXXFLAGS} -I${GTEST_DIR}/include -I${GMOCK_DIR}/include -I${ADT_DIR} -o $@ -c $<




clean:
	rm -rf *.o $(TESTCASE_DIR)/*.o $(ADT_DIR)/*.o $(OTHER_DIR)/*.o *.a test
