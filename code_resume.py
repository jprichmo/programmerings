# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
#       NAME: Jason Paul Richmond       PHONE: 574.855.6954
#       DATE: 2018.04.13                EMAIL: jprichmo@indiana.edu
#       FILE: code_resume.py            (see reverse for text)
abt = { 'name':'Jason Paul Richmond', 'phone':'574.855.6954',
        'email':'jprichmo@indiana.edu', 'date':'2018.04.16',
        'file':'code_resume.txt', 'see':'(see reverse for code)' }
def rep(c,r): # repeat characters
    s = ""
    for i in range(r): s += c
    return s
print rep("# ",40), "\n#"
print "#", rep(" ",5), "NAME:", abt['name'], rep(" ",5), "PHONE:", abt['phone']
print "#", rep(" ",5), "DATE:", abt['date'], rep(" ",14),"EMAIL:", abt['email']
print "#", rep(" ",5), "FILE:", abt['file'], rep(" ",9), abt['see'], "\n#"
print rep(" ",3), "Creative and detail-oriented Master of Science student",\
    "searching for full-\n", rep(" ",3), "or part-time summer employment,",\
    "open to continuing part-time through the\n", rep(" ",3), "school year.",\
    "Brings programming chops from teaching students how code and\n",\
    rep(" ",3), "computation work. Has experience dealing with clients and",\
    "engineering\n", rep(" ",3), "solutions for a family-owned small business."

# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # EDUCATION
edu = { 'ms':'Master of Science', 'ms_sch':'Indiana University South Bend',
        'ms_maj':'Computer Science', 'ms_grad':'2019',
        'ba':'Bachelor of Arts', 'ba_sch':'Indiana University Bloomington',
        'ba_maj':'Linguistics, Anthropology, Economics', 'ba_grad':'2008' }
# calculate major GPA
gpa = lambda a, am, bm: (a*4.0 + am*3.7 + bm*2.7)/(a + am + bm)
print "\n\n", rep("# ",40) + "\n#\n# " + rep(" ",6), "EDUCATION" + "\n#"
print rep(" ",4) + edu['ms_sch'] + rep(" ",42) + edu['ms_grad']
print rep(" ",8) + edu['ms'] + ": " + edu['ms_maj'] + rep(" ",20)\
    + "Program GPA:", round(gpa(4,1,1),1) # GPA: 3.7
print "\n", rep(" ",4) + edu['ba_sch'] + rep(" ",41) + edu['ba_grad']
print rep(" ",7), edu['ba'] + ":", edu['ba_maj'], rep(" ",7), "GPA: 3.1\n\n"

# # # # # # # # # # # # # # # # # # # # # # # # # # # RELEVANT WORK EXPERIENCE
wrk = { 'tutor':'Walk-in/Embedded Tutor', 'cs':'Computer Science Department',
        'ace':'Academic Center for Excellence', 'td':'2016 ~ Present',
        'dsign':'Technician and Graphic Designer', 'dd':'2008 ~ 2017',
        'attr':'Attractive Sign & Lighting, Inc'}
# tutoring string
def tutor(): return wrk['tutor'] + rep(" ",39) + wrk['td'] + "\n"\
            + rep(" ",8) + "IUSB ~ " + wrk['ace'] + " ~ " + wrk['cs']
# sign technician etc string
def dsign(): return wrk['dsign'] + rep(" ",33) + wrk['dd'] + "\n"\
            + rep(" ",8) + wrk['attr']
print rep("# ",40) + "\n#\n#" + rep(" ",6), "RELEVANT WORK EXPERIENCE" + "\n#"
print rep(" ",4) + tutor() + "\n"
print rep(" ",7), "Spend time helping majors and non-majors comprehend class",\
    "material and\n", rep(" ",7), "figure out why their code has become",\
    "obstinately self-aware. Requires\n", rep(" ",7), "interpersonal",\
    "communication, intuitive recognition of when students\n", rep(" ",7),\
    "are not grokking the concepts, and shifts in imagination to recast\n",\
    rep(" ",7), "difficult computing problems in ways they can understand.\n"
print rep(" ",4) + dsign() + "\n"
print rep(" ",7), "Designed, manufactured, installed, and serviced signs all",\
    "across\n", rep(" ",7), "Chicagoland. Used an algorithmic approach to",\
    "troubleshooting during\n", rep(" ",7), "service calls including",\
    "interviews with customers to ensure the proper\n", rep(" ",7), "fix.",\
    "Compiled estimated material and labor costs for sales quotes.\n",\
    rep(" ",7), "Operated heavy machinery and dangerous equipment such as",\
    "booms, cranes,\n", rep(" ",7), "augers, trenchers, and torches. Crafted",\
    "company logo and coded company\n", rep(" ",7), "website which",\
    "entailed writing all of the copy.\n"\

# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # SKILLS
print rep("# ",40) + "\n#\n#" + rep(" ",6), "SKILLS" + "\n#"
print rep(" ",7), "Languages: C++, C#, Java, Python, HTML, CSS, Javascript\n"
print rep(" ",7), "Tools/Environments: Unity, Processing, Keras, Git\n"
print rep(" ",7), "Graphic Design: Inkscape, CorelDRAW, Adobe Suite"
