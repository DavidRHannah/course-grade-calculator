#include "Year.h"
#include <map>

Year::Year(const string& yearName, const vector<Quarter>& quarters)
    : m_name(yearName), m_quarters(quarters)
{}

Year::Year()
    : m_name(" "), m_quarters({})
{}

void Year::setName(const string & name)
{
    m_name = name;
}

void Year::addQuarter(const Quarter& quarter)
{
    m_quarters.push_back(quarter);
}

Quarter* Year::getQuarter(const std::string& name)
{
    for (auto& quarter : m_quarters)
    {
        if (quarter.getName() == name)
        {
            return &quarter;
        }
    }
    return nullptr;
}

string Year::toCSV()
{
    std::ostringstream oss;
    oss << "Quarter,Course,Group,Weight,Assignment,Points_Earned,Point_Total\n";

    string csvLine("");
    vector<string> data;
    for (auto& quarter : m_quarters)
    {
        data.clear();
        string qtr = quarter.getName();
        data.push_back(qtr);
        auto courses = quarter.getCourses();
        for (auto& course : *courses)
        {
            string crs = course.getName();
            data.push_back(crs);
            auto groups = course.getGroups();
            for (auto& group : *groups)
            {
                string grpN = group.getName();
                string grpW = std::to_string(group.getWeight());

                data.push_back(grpN);
                data.push_back(grpW);

                auto assignments = group.getAssignments();
                for (auto& assignment : *assignments)
                {
                    string asnN = assignment.getName();
                    string asnPe = std::to_string(assignment.getPointsEarned());
                    string asnPt = std::to_string(assignment.getPointTotal());
                    
                    data.push_back(asnN);
                    data.push_back(asnPe);
                    data.push_back(asnPt);

                    oss << qtr << ',' << crs << ',' << grpN << ',' << grpW << ','
                        << asnN << ',' << asnPe << ',' << asnPt << '\n';

                }
            }
        }
    }
    return oss.str();
}

void Year::fromCSV(const std::string& filename)
{
    std::ifstream file(filename);
    if (!file.is_open())
    {
        std::cerr << "Error opening file: " << filename << std::endl;
        return;
    }

    std::string line;
    getline(file, line);

    while (getline(file, line))
    {
        std::stringstream lineStream(line);
        std::string quarter, course, group, weightStr, assignment, pointsEarnedStr, pointTotalStr;

        getline(lineStream, quarter, ',');
        getline(lineStream, course, ',');
        getline(lineStream, group, ',');
        getline(lineStream, weightStr, ',');
        getline(lineStream, assignment, ',');
        getline(lineStream, pointsEarnedStr, ',');
        getline(lineStream, pointTotalStr, ',');

        try
        {
            double weight = std::stod(weightStr);
            double pointsEarned = std::stod(pointsEarnedStr);
            double pointTotal = std::stod(pointTotalStr);

            Quarter* qtr = findOrCreateQuarter(quarter);

            Course* crs = qtr->findOrCreateCourse(course);

            Group* grp = crs->findOrCreateGroup(group, weight);

            grp->addAssignment(Assignment(assignment, pointsEarned, pointTotal));
        }
        catch (const std::exception& e)
        {
            std::cerr << "Error processing line: " << line << "\n" << e.what() << std::endl;
        }
    }
}

Quarter* Year::findOrCreateQuarter(const std::string& name)
{
    for (Quarter& q : m_quarters)
    {
        if (q.getName() == name)
            return &q;
    }
    m_quarters.emplace_back(name);
    return &m_quarters.back();
}

void Year::display() const
{
    for (const auto& quarter : m_quarters)
    {
        quarter.display();
    }
}