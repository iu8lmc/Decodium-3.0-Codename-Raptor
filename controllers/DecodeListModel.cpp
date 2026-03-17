#include "DecodeListModel.hpp"

DecodeListModel::DecodeListModel(QObject *parent)
    : QAbstractListModel(parent)
{
}

int DecodeListModel::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;
    return static_cast<int>(m_decodes.size());
}

QVariant DecodeListModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return {};

    const int row = index.row();
    if (row < 0 || row >= static_cast<int>(m_decodes.size()))
        return {};

    const auto &entry = m_decodes.at(row);

    switch (role) {
    case UtcRole:
        return entry.utc;
    case DbRole:
        return entry.db;
    case DtRole:
        return entry.dt;
    case FreqRole:
        return entry.freq;
    case MessageRole:
        return entry.message;
    case IsCQRole:
        return entry.isCQ;
    case IsNewRole:
        return entry.isNew;
    case ColorRole:
        return entry.color;
    case IsB4Role:
        return entry.isB4;
    case IsDirectedRole:
        return entry.isDirected;
    case IsLotwUserRole:
        return entry.isLotwUser;
    case Qt::DisplayRole:
        return QStringLiteral("%1 %2 %3 %4 %5")
            .arg(entry.utc)
            .arg(entry.db, 3)
            .arg(entry.dt, 5, 'f', 1)
            .arg(entry.freq, 4)
            .arg(entry.message);
    default:
        return {};
    }
}

QHash<int, QByteArray> DecodeListModel::roleNames() const
{
    return {
        { UtcRole,       "utc" },
        { DbRole,        "db" },
        { DtRole,        "dt" },
        { FreqRole,      "freq" },
        { MessageRole,   "message" },
        { IsCQRole,      "isCQ" },
        { IsNewRole,     "isNew" },
        { ColorRole,     "color" },
        { IsB4Role,      "isB4" },
        { IsDirectedRole, "isDirected" },
        { IsLotwUserRole, "isLotwUser" },
    };
}

int DecodeListModel::count() const
{
    return static_cast<int>(m_decodes.size());
}

void DecodeListModel::addDecode(const QString &utc, int db, double dt, int freq,
                                 const QString &message, bool isCQ, bool isNew,
                                 const QColor &color, bool isB4, bool isDirected,
                                 bool isLotwUser)
{
    const int row = static_cast<int>(m_decodes.size());
    beginInsertRows(QModelIndex(), row, row);

    DecodeEntry entry;
    entry.utc = utc;
    entry.db = db;
    entry.dt = dt;
    entry.freq = freq;
    entry.message = message;
    entry.isCQ = isCQ;
    entry.isNew = isNew;
    entry.color = color;
    entry.isB4 = isB4;
    entry.isDirected = isDirected;
    entry.isLotwUser = isLotwUser;

    m_decodes.append(entry);

    endInsertRows();
    emit countChanged();
}

void DecodeListModel::clear()
{
    if (m_decodes.isEmpty())
        return;

    beginResetModel();
    m_decodes.clear();
    endResetModel();
    emit countChanged();
}

void DecodeListModel::addDemoDecodes()
{
    const QColor cqColor(QStringLiteral("#4CAF50"));
    const QColor myCallColor(QStringLiteral("#FF5252"));
    const QColor normalColor(QStringLiteral("#B0BEC5"));

    addDecode("174500", -10, 0.3, 1012, "CQ DX IU8LMC JN70",      true,  false, cqColor);
    addDecode("174500",  -5, 0.1,  820, "CQ K1ABC FN42",           true,  false, cqColor);
    addDecode("174500", -18, 0.5, 1455, "W3XYZ K1ABC -12",         false, false, normalColor);
    addDecode("174500",  -2, 0.0,  600, "CQ POTA VE3ABC EN82",     true,  false, cqColor);
    addDecode("174500", -14, 0.2, 1890, "JA1ZZZ W3XYZ R-08",       false, false, normalColor);
    addDecode("174500",   3, 0.1, 1200, "K1ABC IU8LMC -05",        false, true,  myCallColor, false, true);
    addDecode("174500", -22, 0.8,  350, "CQ JH1NBN PM95",          true,  false, cqColor);
    addDecode("174500",  -8, 0.4, 2100, "VK3ABC JA1ZZZ RR73",      false, false, normalColor);
}

QVariantMap DecodeListModel::get(int row) const
{
    QVariantMap map;
    if (row < 0 || row >= static_cast<int>(m_decodes.size()))
        return map;

    const auto &entry = m_decodes.at(row);
    map[QStringLiteral("utc")] = entry.utc;
    map[QStringLiteral("db")] = entry.db;
    map[QStringLiteral("dt")] = entry.dt;
    map[QStringLiteral("freq")] = entry.freq;
    map[QStringLiteral("message")] = entry.message;
    map[QStringLiteral("isCQ")] = entry.isCQ;
    map[QStringLiteral("isNew")] = entry.isNew;
    map[QStringLiteral("color")] = entry.color;
    map[QStringLiteral("isB4")] = entry.isB4;
    map[QStringLiteral("isDirected")] = entry.isDirected;
    map[QStringLiteral("isLotwUser")] = entry.isLotwUser;
    return map;
}
