#pragma once

#include <iostream>

class tree {
	struct Node {
		int data;
		std::shared_ptr<Node> left;
		std::shared_ptr<Node> right;
	};
	std::shared_ptr<Node> root;
public:
	tree() {
		root = nullptr;
	}
	tree(int temp) {
		std::shared_ptr<Node> t (new(Node));
		root = t;
		root->data = temp;
		root->left = nullptr;
		root->right = nullptr;
	}

	~tree() {
		std::cout << "tree has deleted";
	}

	void addData(int temp){
		if (root) {
			if (temp < root->data) {
				if (!(root->left)) {
					std::shared_ptr<Node> leave(new(Node));
					leave->data = temp;
					leave->left = nullptr;
					leave->right = nullptr;
					root->left = leave;
				}
				else {
					addBranch(temp, root->left);
				}
			}
			else {
				if (!(root->right)) {
					std::shared_ptr<Node> leave(new(Node));
					leave->data = temp;
					leave->left = nullptr;
					leave->right = nullptr;
					root->right = leave;
				}
				else {
					addBranch(temp, root->right);
				}
			}
		}
		else {
			std::shared_ptr<Node> t(new(Node));
			root = t;
			root->data = temp;
			root->left = nullptr;
			root->right = nullptr;
		}
	}

	void addBranch(int temp,std::shared_ptr<Node> branch) {
			if (temp < branch->data) {
				if (!(branch->left)) {
					std::shared_ptr<Node> leave(new(Node));
					leave->data = temp;
					leave->left = nullptr;
					leave->right = nullptr;
					branch->left = leave;
				}
				else {
					addBranch(temp, branch->left); 
				}
			}
			else {
				if (!(branch->right)) {
					std::shared_ptr<Node> leave(new(Node));
					leave->data = temp;
					leave->left = nullptr;
					leave->right = nullptr;
					branch->right = leave;
				}
				else { 
					addBranch(temp, branch->right); 
				}
			}
	}

	void print() {
		if (root) {
			std::cout << root->data << "\n";
			if (root->left) {
				print(root->left);
			}
			if (root->right) {
				print(root->right);
			}
		}
	};

	void print(std::shared_ptr<Node> branch) {
		std::cout << branch->data << "\n";
		if (branch->left) {
				print(branch->left);
		}
		if (branch->right) {
				print(branch->right);
		}
	};

};
