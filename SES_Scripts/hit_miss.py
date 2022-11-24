import os


sequence = [12, 15, 22, 15, 5, 22, 32, 15, 32]
Cm_Loc = 7
Mm_Loc = 50

def get_CML(MML, CL):
    return MML % CL

def get_TAG(MML, CL):
    return MML // CL

sequence_entry = None
hit_miss_list = []
sequence_occured = []

os.system('cls')

for seq_no in sequence:
    entryd = dict(mml=seq_no, cml=get_CML(seq_no, Cm_Loc), tag=get_TAG(seq_no, Cm_Loc), valid=1)
    if sequence_entry is None:
        sequence_entry = []
        sequence_entry.append(entryd)
        hit_miss_list.append((sequence_entry[0], "miss"))
        sequence_occured.append(seq_no)
    else:
        if seq_no in sequence_occured:
            for entry in sequence_entry:
                if entry['mml'] == seq_no:
                    for prev_entry in reversed(hit_miss_list):
                        if prev_entry[0]['cml'] == entry['cml']:
                            if prev_entry[0]['tag'] == entry['tag'] and prev_entry[0]['valid'] == entry['valid']:
                                hit_miss_list.append((entry, "hit"))
                            else:
                                hit_miss_list.append((entry, "miss"))
                            break
        else:
            sequence_entry.append(entryd)
            hit_miss_list.append((entryd, "miss"))
            sequence_occured.append(seq_no)

for entry in hit_miss_list:
    print(entry)
