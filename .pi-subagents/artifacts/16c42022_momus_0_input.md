# Task for momus

You are a CRITICAL REVIEWER. Your job is to rigorously audit all 14 graph theory notes in /home/xieguiawu/Documents/Obsidian Vault/Math/Graph_Theory/ for quality.

Read ALL .md files in that directory (exclude PDFs). For each file, check:

1. **YAML Front Matter**: 
   - Must have title, tags, created fields
   - Tags must match vault conventions (学科英文驼峰 + 功能中文)
   - No single quotes in tags
   - Title format: Title Case in English

2. **Mathematical Content**:
   - All math must use proper LaTeX (no Unicode replacements like →, ∀, ∃, ∈, etc.)
   - All LaTeX delimiters must be balanced ($...$ and $$...$$)
   - No ASCII substitute symbols

3. **Mermaid Diagrams**:
   - Should render properly (correct syntax)
   - At least 3-6 per file depending on topic

4. **Internal Links**: 
   - [[links]] should point to existing notes in the vault
   - Check that references to other graph theory notes use correct filenames

5. **Structure**:
   - Proper heading hierarchy (# → ## → ###)
   - Callout usage ([!note], [!tip], [!warning], etc.)
   - No unnecessary horizontal rules
   - 符号速查 section present
   - 相关链接 section present

6. **Completeness**: 
   - Content matches what was specified for each note
   - No truncated/empty sections
   - Complete sentences, not stubs

7. **Content Accuracy**:
   - Verify the content matches actual graph theory (Griffin textbook, Ch1-10)
   - No major mathematical errors

For each file found, either:
- APPROVE: if all quality standards are met
- FLAG: specific issues found with exact file + line reference

Give a FINAL VERDICT: PASS or FAIL for the entire set.

Focus especially on these critical notes:
- Graph - Adjacency Matrix & Spectrum.md (core algebraic graph theory)
- Every Matrix is a Graph.md (core insight note)
- Jordan Form through Graph Theory.md (complex connection)
- Graph - Laplacian & Spectral Clustering.md (important applications)

Write your review COMPLETELY. Do not truncate.

## Acceptance Contract
Acceptance level: checked
Completion is not accepted from prose alone. End with a structured acceptance report.

Criteria:
- criterion-1: Implement the requested change without widening scope

Required evidence: changed-files, tests-added, commands-run, residual-risks, no-staged-files

Finish with a fenced JSON block tagged `acceptance-report` in this shape:
Use empty arrays when no items apply; array fields contain strings unless object entries are shown.
```acceptance-report
{
  "criteriaSatisfied": [
    {
      "id": "criterion-1",
      "status": "satisfied",
      "evidence": "specific proof"
    }
  ],
  "changedFiles": [
    "src/file.ts"
  ],
  "testsAddedOrUpdated": [
    "test/file.test.ts"
  ],
  "commandsRun": [
    {
      "command": "command",
      "result": "passed",
      "summary": "short result"
    }
  ],
  "validationOutput": [
    "validation output or concise summary"
  ],
  "residualRisks": [
    "none"
  ],
  "noStagedFiles": true,
  "diffSummary": "short description of the diff",
  "reviewFindings": [
    "blocker: file.ts:12 - issue found, or no blockers"
  ],
  "manualNotes": "anything else the parent should know"
}
```