#include "../s21_matrix_oop.h"

void S21Matrix::set_rows(int new_rows) {
  if (new_rows < 0) {
    throw std::out_of_range("Matrix rows must be non-negative");
  }

  if (new_rows != rows_) {
    int min_rows = (rows_ < new_rows) ? rows_ : new_rows;

    double** new_matrix = new double*[new_rows]();
    for (int i = 0; i < new_rows; i++) {
      new_matrix[i] = new double[cols_]();
    }

    for (int i = 0; i < min_rows; i++) {
      for (int j = 0; j < cols_; j++) {
        new_matrix[i][j] = matrix_[i][j];
      }
    }

    for (int i = 0; i < rows_; i++) {
      delete[] matrix_[i];
    }
    delete[] matrix_;

    matrix_ = std::move(new_matrix);
    rows_ = new_rows;
  }
}

void S21Matrix::set_cols(int new_cols) {
  if (new_cols < 0) {
    throw std::out_of_range("Matrix columns must be non-negative");
  }

  if (new_cols != cols_) {
    int min_cols = (cols_ < new_cols) ? cols_ : new_cols;

    double** new_matrix = new double*[rows_]();
    for (int i = 0; i < rows_; i++) {
      new_matrix[i] = new double[new_cols]();
    }

    for (int i = 0; i < rows_; i++) {
      for (int j = 0; j < min_cols; j++) {
        new_matrix[i][j] = matrix_[i][j];
      }
    }

    for (int i = 0; i < rows_; i++) {
      delete[] matrix_[i];
    }
    delete[] matrix_;

    matrix_ = std::move(new_matrix);
    cols_ = new_cols;
  }
}

int S21Matrix::get_rows() const { return this->rows_; }

int S21Matrix::get_cols() const { return this->cols_; }

void S21Matrix::print() {
  for (int i = 0; i < this->rows_; i++) {
    for (int j = 0; j < this->cols_; j++) {
      std::cout << this->matrix_[i][j];
      std::cout << "\t";
    }
    std::cout << "\n\n";
  }
}

bool S21Matrix::eq_sizes(const S21Matrix& other) {
  return (this->cols_ == other.cols_ && this->rows_ == other.rows_);
}

bool S21Matrix::available_to_mul(const S21Matrix& other) {
  return (this->cols_ == other.rows_);
}

bool S21Matrix::is_square() { return (this->cols_ == this->rows_); }

bool S21Matrix::max_in_column(const S21Matrix& A, int row, int column) {
  double elem = A.matrix_[row][column];
  double max = elem;
  for (int i = row; i < A.rows_; i++) {
    if (std::abs(A.matrix_[i][column]) > std::abs(max)) {
      max = A.matrix_[i][column];
    }
  }
  return std::abs(elem) < std::abs(max) ? 0 : 1;
}

bool S21Matrix::swap_rows(S21Matrix& A, int n) {
  int size = A.rows_;
  bool done = 0;
  for (int i = n + 1; i < size && done == 0; i++) {
    if ((std::abs(A.matrix_[i][n]) > EPS) && max_in_column(A, i, n)) {
      for (int j = 0; j < size; j++) {
        double temp = A.matrix_[i][j];
        A.matrix_[i][j] = A.matrix_[n][j];
        A.matrix_[n][j] = temp;
      }
      done = 1;
    }
  }
  return done;
}

S21Matrix S21Matrix::get_minor(int row, int column) {
  S21Matrix res(this->rows_ - 1, this->cols_ - 1);
  int m_row = 0;
  int m_column = 0;
  for (int i = 0; i < this->rows_; i++) {
    if (i != row) {
      for (int j = 0; j < this->cols_; j++) {
        if (j != column) {
          res.matrix_[m_row][m_column] = this->matrix_[i][j];
          m_column++;
        }
      }
      m_row++;
      m_column = 0;
    }
  }
  return res;
}