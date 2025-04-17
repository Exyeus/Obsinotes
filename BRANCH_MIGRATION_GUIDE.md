# Git 分支迁移通知

**2025年4月7日**  

## 🔄 变更内容
1. **主分支迁移**  
   - 原 `slide` 分支已重命名为 `main`（新主分支）
   - 原 `main` 分支已重命名为 `legacy-main`（历史备份分支）

2. **远程分支状态**  
   ```bash
   # 当前远程分支结构
   remotes/origin/main          # 新主分支（原slide）
   remotes/origin/legacy-main   # 原main分支备份
   remotes/origin/slide         # 保持不变的临时分支
   ```

## ⚠️ 需执行操作
所有开发者**必须**在下次开发前完成以下步骤,确保本地git仓库于GitHub同步：

### 1. 清理本地仓库
```bash
# 删除旧main分支（如果存在）
git branch -D main

# 删除旧develop分支（如果存在）
git branch -D develop

# 清理远程分支缓存
git remote prune origin
```

### 2. 获取最新分支结构
```bash
# 强制同步远程仓库状态
git fetch --all --prune
```

### 3. 切换至新主分支
```bash
# 创建并切换到本地main分支
git checkout -b main origin/main

# 设置上游追踪
git branch -u origin/main
```

### 4. 验证配置
```bash
# 检查分支关联关系
git remote show origin

# 期望输出应包含：
#   Local branch configured for 'git pull': main
#   Local branch configured for 'git push': main
```

## 🚨 重要提醒
1. **禁止直接操作**  
   - 不要向 `legacy-main` 分支提交新代码
   - 不要删除远程 `legacy-main` 分支

2. **冲突处理**  
   如果遇到 `fatal: refusing to merge unrelated histories` 错误：
   ```bash
   git pull origin main --allow-unrelated-histories
   ```



**Q1: 如何访问旧历史版本？**  
```bash
# 查看legacy-main分支
git checkout legacy-main
git pull origin legacy-main
```



