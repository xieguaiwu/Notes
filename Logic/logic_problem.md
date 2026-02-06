# Problem

$$
\operatorname{SIMPL}(H_1 \lor H_2 \Gamma) = 
\left\{
\begin{array}{l@{\quad}l}
t & \text{IF } K_1 = t \text{ OR } K_2 = t \\
f & \text{IF } K_1 = f \text{ OR } K_2 = f \\
K_1 \lor K_2 & \text{OTHERWISE} \\
\hline
H_1 \rightarrow H_2, \Gamma & \\
\neg H_2 \Gamma & \\
H_1 \lor H_2, \Gamma & 
\end{array}
\right.$$ 


Procedure $Hp$ for deduction in $Hc$?

1. If $\mathsf{G}$ is axiom or $\mathsf{G}\in\Gamma$ return $<\mathsf{G}>$
2. If $\{\neg A, A \}\subseteq \Gamma$ if $G\neq\Box$ then return Proof $D_{EF} (A,\mathsf{G})$ else $<\neg A,A>$
3. If $\neg\neg A\in\Gamma$ let $D=Hp((\Gamma\\ \{\neg\neg A \})\cup\{ A,B \},\mathsf{G})$
4. If $A\textasciicircum BE\Gamma$ let $D=Hp((\Gamma\\ \{A\textasciicircum B \})\cup\{ A,B \},\mathsf{G})$
