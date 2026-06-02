#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>

using namespace std;

// 打印矩阵（带小数点对齐）
void printMatrix(const vector<vector<double>>& A, const string& label = "") {
    if (!label.empty()) cout << label << ":\n";
    for (const auto& row : A) {
        for (double val : row)
            cout << setw(10) << fixed << setprecision(4) << val;
        cout << "\n";
    }
    cout << "\n";
}

// 打印增广矩阵 [A | B]，中间画一条竖线
void printAugmented(const vector<vector<double>>& A, const vector<vector<double>>& B,
                    const string& label = "") {
    if (!label.empty()) cout << label << ":\n";
    int n = A.size();
    for (int i = 0; i < n; ++i) {
        for (double val : A[i]) cout << setw(10) << fixed << setprecision(4) << val;
        cout << "  |";
        for (double val : B[i]) cout << setw(10) << fixed << setprecision(4) << val;
        cout << "\n";
    }
    cout << "\n";
}

// 高斯-若尔当消元法求逆矩阵
// 返回 true 表示成功，false 表示矩阵不可逆
bool gaussJordanInverse(vector<vector<double>> A, vector<vector<double>>& inv) {
    int n = A.size();

    // --- Step 1: 初始化 inv = I ---
    inv.assign(n, vector<double>(n, 0.0));
    for (int i = 0; i < n; ++i) inv[i][i] = 1.0;

    cout << "========== 开始 Gauss-Jordan 消元 ==========\n\n";
    printAugmented(A, inv, "初始增广矩阵 [A | I]");

    // --- 前向消去：化为行阶梯形 (REF) ---
    cout << "------ 阶段 1: 前向消去（→ REF）------\n\n";
    for (int col = 0; col < n; ++col) {
        // 选主元：从当前行往下找绝对值最大的（列主元策略，减少数值误差）
        int pivotRow = col;
        double maxVal = fabs(A[col][col]);
        for (int row = col + 1; row < n; ++row) {
            if (fabs(A[row][col]) > maxVal) {
                maxVal = fabs(A[row][col]);
                pivotRow = row;
            }
        }

        if (maxVal < 1e-10) {
            cout << "列 " << col + 1 << " 无法找到非零主元 → 矩阵不可逆\n";
            return false;
        }

        // 若主元不在当前行，则交换行
        if (pivotRow != col) {
            swap(A[col], A[pivotRow]);
            swap(inv[col], inv[pivotRow]);
            cout << "交换 R" << col + 1 << " ↔ R" << pivotRow + 1 << "\n\n";
        }

        // 主元归一化：R_col ← R_col / pivot
        double pivot = A[col][col];
        if (fabs(pivot - 1.0) > 1e-10) {
            for (int j = 0; j < n; ++j) {
                A[col][j]   /= pivot;
                inv[col][j] /= pivot;
            }
            cout << "R" << col + 1 << " ← R" << col + 1 << " / " << pivot
                 << "  (主元归一化)\n\n";
        }

        // 消去下方行：R_i ← R_i - A[i][col] * R_col
        for (int row = col + 1; row < n; ++row) {
            double factor = A[row][col];
            if (fabs(factor) < 1e-10) continue;  // 已经是 0，跳过
            for (int j = 0; j < n; ++j) {
                A[row][j]   -= factor * A[col][j];
                inv[row][j] -= factor * inv[col][j];
            }
            cout << "R" << row + 1 << " ← R" << row + 1 << " - (" << factor << ") × R" << col + 1 << "\n";
        }
        cout << "\n";
        printAugmented(A, inv, "当前状态");
    }

    cout << "✅ REF 达成，矩阵满秩，继续后向消去…\n\n";

    // --- 后向消去：化为行最简形 (RREF) ---
    cout << "------ 阶段 2: 后向消去（→ RREF）------\n\n";
    for (int col = n - 1; col > 0; --col) {
        for (int row = col - 1; row >= 0; --row) {
            double factor = A[row][col];
            if (fabs(factor) < 1e-10) continue;
            for (int j = 0; j < n; ++j) {
                A[row][j]   -= factor * A[col][j];
                inv[row][j] -= factor * inv[col][j];
            }
            cout << "R" << row + 1 << " ← R" << row + 1 << " - (" << factor << ") × R" << col + 1 << "\n";
        }
        cout << "\n";
        printAugmented(A, inv, "当前状态");
    }

    cout << "========== Gauss-Jordan 消元完成 ==========\n\n";
    return true;
}

int main() {
    // 原题矩阵
    vector<vector<double>> A = {
        {1, 2, 5},
        {4, 5, 6},
        {2, 3, 1}
    };

    cout << "原矩阵 A:\n";
    printMatrix(A);

    vector<vector<double>> invA;
    bool success = gaussJordanInverse(A, invA);

    if (!success) {
        cout << "❌ 矩阵不可逆。\n";
        return 1;
    }

    cout << "✅ 逆矩阵 A⁻¹:\n";
    printMatrix(invA);

    // --- 验证 A × A⁻¹ = I ---
    cout << "------ 验证 A × A⁻¹ ------ \n";
    int n = A.size();
    vector<vector<double>> I(n, vector<double>(n, 0.0));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            for (int k = 0; k < n; ++k)
                I[i][j] += A[i][k] * invA[k][j];

    printMatrix(I, "A × A⁻¹ (应为单位阵)");

    // 检查误差
    double maxError = 0.0;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) {
            double expected = (i == j) ? 1.0 : 0.0;
            maxError = max(maxError, fabs(I[i][j] - expected));
        }

    cout << "最大误差: " << scientific << maxError << "\n";
    if (maxError < 1e-10)
        cout << "✅ 验证通过！\n";
    else
        cout << "⚠️  误差偏大，请检查。\n";

    return 0;
}
