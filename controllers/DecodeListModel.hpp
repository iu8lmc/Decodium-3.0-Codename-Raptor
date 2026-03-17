#ifndef DECODELISTMODEL_HPP
#define DECODELISTMODEL_HPP

#include <QAbstractListModel>
#include <QQmlEngine>
#include <QColor>
#include <QString>
#include <QList>

class DecodeListModel : public QAbstractListModel
{
    Q_OBJECT
    QML_ELEMENT

    Q_PROPERTY(int count READ count NOTIFY countChanged)

public:
    enum DecodeRoles {
        UtcRole = Qt::UserRole + 1,
        DbRole,
        DtRole,
        FreqRole,
        MessageRole,
        IsCQRole,
        IsNewRole,
        ColorRole,
        IsB4Role,
        IsDirectedRole,
        IsLotwUserRole
    };
    Q_ENUM(DecodeRoles)

    explicit DecodeListModel(QObject *parent = nullptr);
    ~DecodeListModel() override = default;

    // QAbstractListModel interface
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QHash<int, QByteArray> roleNames() const override;

    int count() const;

    Q_INVOKABLE void addDecode(const QString &utc, int db, double dt, int freq,
                                const QString &message, bool isCQ, bool isNew,
                                const QColor &color, bool isB4 = false,
                                bool isDirected = false,
                                bool isLotwUser = false);
    Q_INVOKABLE void clear();
    Q_INVOKABLE QVariantMap get(int row) const;
    Q_INVOKABLE void addDemoDecodes();

signals:
    void countChanged();

private:
    struct DecodeEntry {
        QString utc;
        int db = 0;
        double dt = 0.0;
        int freq = 0;
        QString message;
        bool isCQ = false;
        bool isNew = false;
        QColor color;
        bool isB4 = false;
        bool isDirected = false;
        bool isLotwUser = false;
    };

    QList<DecodeEntry> m_decodes;
};

#endif // DECODELISTMODEL_HPP
