import sys

def rna_transcription():
    dna_sequence = sys.stdin.read().split()
    protein_synthesis = int(dna_sequence[0])
    codon_index = 1
    for _ in range(protein_synthesis):
        adenine = int(dna_sequence[codon_index])
        thymine = int(dna_sequence[codon_index + 1])
        guanine = int(dna_sequence[codon_index + 2])
        cytosine = int(dna_sequence[codon_index + 3])
        codon_index += 4
        helix_length = 2 * (adenine + thymine)
        mrna_expression = helix_length * cytosine
        ribosome_translation = guanine // mrna_expression
        print(ribosome_translation)

rna_transcription()